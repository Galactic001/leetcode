import os
import re

# --- CONFIGURATION ---
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
ROOT_DIR = os.path.dirname(SCRIPT_DIR)
README_PATH = os.path.join(ROOT_DIR, 'README.md')
FOLDER_PATTERN = re.compile(r'^(\d+)[-_](.+)$')

def get_solved_problems():
    problems = []
    for batch_folder in os.listdir(ROOT_DIR):
        batch_path = os.path.join(ROOT_DIR, batch_folder)
        if not os.path.isdir(batch_path) or not re.match(r'\d+-\d+', batch_folder):
            continue

        for problem_folder in os.listdir(batch_path):
            match = FOLDER_PATTERN.match(problem_folder)
            if match:
                problem_id = match.group(1)
                raw_name = match.group(2)
                title = raw_name.replace('-', ' ').replace('_', ' ').strip()
                slug = raw_name.replace('_', '-').lower()
                leetcode_url = f"https://leetcode.com/problems/{slug}/"
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
    lines = ["| ID | Problem | Solution |", "|:---:|:---|:---:|"]
    for p in problems:
        lines.append(f"| {p['id']} | [{p['title']}]({p['url']}) | [📂 Code]({p['path']}) |")
    return "\n".join(lines)

def update_readme():
    if not os.path.exists(README_PATH):
        return

    with open(README_PATH, 'r', encoding='utf-8') as f:
        content = f.read()

    # ---------------------------------------------
    # FIX: You must define these markers!
    # ---------------------------------------------
    start_marker = ""
    end_marker = ""

    # SAFETY CHECK: Ensure both markers exist in the README content
    if start_marker not in content or end_marker not in content:
        print(f"Error: Markers '{start_marker}' and '{end_marker}' not found in README. No changes made.")
        # We return exit code 1 here manually so the Action knows it failed
        exit(1) 

    # SAFE SPLIT METHOD
    try:
        before_part = content.split(start_marker)[0]
        after_part = content.split(end_marker)[1]
    except IndexError:
        print("Error: Markers appear corrupted.")
        exit(1)

    problems = get_solved_problems()
    new_table = generate_markdown(problems)
    
    # Reassemble the file
    new_content = f"{before_part}{start_marker}\n\n{new_table}\n\n{end_marker}{after_part}"

    with open(README_PATH, 'w', encoding='utf-8') as f:
        f.write(new_content)
    print("Success: README updated safely.")

if __name__ == "__main__":
    update_readme()