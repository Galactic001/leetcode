import os
import re

# --- CONFIGURATION ---
# Get the absolute path of the folder containing this script (Scripts/)
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
# The repository root is the parent of SCRIPT_DIR
ROOT_DIR = os.path.dirname(SCRIPT_DIR)
README_PATH = os.path.join(ROOT_DIR, 'README.md')

# Regex matches folders like "0001-two-sum" or "1984_Minimum_Difference"
FOLDER_PATTERN = re.compile(r'^(\d+)[-_](.+)$')

def get_solved_problems():
    problems = []
    
    # Iterate over folders in the root directory (looking for "00-99", "100-199", etc.)
    for batch_folder in os.listdir(ROOT_DIR):
        batch_path = os.path.join(ROOT_DIR, batch_folder)
        
        # Skip if not a directory or not a numbered batch folder
        if not os.path.isdir(batch_path) or not re.match(r'\d+-\d+', batch_folder):
            continue

        # Iterate over problem folders inside the batch folder
        for problem_folder in os.listdir(batch_path):
            match = FOLDER_PATTERN.match(problem_folder)
            if match:
                problem_id = match.group(1)
                raw_name = match.group(2)
                
                # Normalize title
                title = raw_name.replace('-', ' ').replace('_', ' ').strip()
                # Normalize URL slug (LeetCode uses kebab-case)
                slug = raw_name.replace('_', '-').lower()
                leetcode_url = f"https://leetcode.com/problems/{slug}/"
                
                # Path relative to the README (Root)
                solution_path = f"./{batch_folder}/{problem_folder}"
                
                problems.append({
                    'id': int(problem_id),
                    'title': title,
                    'url': leetcode_url,
                    'path': solution_path
                })

    problems.sort(key=lambda x: x['id'])
    return problems

def generate_markdown(problems):
    lines = [
        "| ID | Problem | Solution |",
        "|:---:|:---|:---:|"
    ]
    for p in problems:
        line = f"| {p['id']} | [{p['title']}]({p['url']}) | [📂 Code]({p['path']}) |"
        lines.append(line)
    return "\n".join(lines)

def update_readme():
    if not os.path.exists(README_PATH):
        print(f"Error: {README_PATH} not found.")
        return

    with open(README_PATH, 'r', encoding='utf-8') as f:
        content = f.read()

    start_marker = ""
    end_marker = ""

    if start_marker not in content or end_marker not in content:
        print("Error: Markers not found in README.md")
        return

    problems = get_solved_problems()
    new_table = generate_markdown(problems)
    
    # Replace content between markers
    pattern = re.compile(f"({re.escape(start_marker)}).*?({re.escape(end_marker)})", re.DOTALL)
    new_content = pattern.sub(f"\\1\n\n{new_table}\n\n\\2", content)

    with open(README_PATH, 'w', encoding='utf-8') as f:
        f.write(new_content)
    
    print(f"Updated README with {len(problems)} problems.")

if __name__ == "__main__":
    update_readme()