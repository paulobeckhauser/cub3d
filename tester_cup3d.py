import subprocess
import re

# Define ANSI color codes
RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
MAGENTA = "\033[1;35m"
CYAN = "\033[1;36m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

def remove_color(string):
    # Regular expression to match ANSI escape codes for color
    ansi_escape_pattern = re.compile(r'\033\[[0-9;]+m')
    # Remove ANSI escape codes from the string
    return ansi_escape_pattern.sub('', string)


def run_make(target=None):
    if target:
        command = ["make", target]
    else:
        command = ["make"]
    result = subprocess.run(command, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"{RED}Make failed{RESET}")
        print(result.stderr)
        return False
    return True


def run_c_program(executable, args=None):
    if args:
        run_command = ["./" + executable] + args
    else:
        run_command = ["./" + executable]
    result = subprocess.run(run_command, capture_output=True, text=True)
    return result


def check_output(output, expected_output):
    return output == expected_output



def main():

    if not run_make("re"):
        return
    
    
    test_cases = [
        {
            "name" : "Without Arguments",
            "executable" : "cub3d",
            "args": None,
            "expected_output": 
            (f"Error!\nIncorrect number of arguments\n")
        },


        {
             "name" : "Not '.cub' file",
            "executable" : "cub3d",
            "args": ["tester_maps/not_cub_file.txt"],
            "expected_output": 
            (f"Error!\nMap is not a '.cub' file\n")
        },

        {
             "name" : "Not '.cub' file",
            "executable" : "cub3d",
            "args": ["tester_maps/example.map"],
            "expected_output": 
            (f"Error!\nMap is not a '.cub' file\n")
        },

        {
            "name" : "Not existent File, but not '.cub'",
            "executable" : "cub3d",
            "args": ["tester_maps/not_existent"],
            "expected_output": 
            (f"Error!\nMap is not a '.cub' file\n")
        },

        {
            "name" : "Not existent File",
            "executable" : "cub3d",
            "args": ["tester_maps/not_existent.cub"],
            "expected_output": 
            (f"Error!\nNo such file or directory\n")
        },

        {
            "name" : "Not floor color line",
            "executable" : "cub3d",
            "args": ["tester_maps/no_floor_line.cub"],
            "expected_output": 
            (f"Error!\nInput for surfaces color(floor or ceiling) does not exist or is in wrong format\n")
        },

        {
            "name" : "Not ceiling color line",
            "executable" : "cub3d",
            "args": ["tester_maps/no_ceiling_line.cub"],
            "expected_output": 
            (f"Error!\nInput for surfaces color(floor or ceiling) does not exist or is in wrong format\n")
        }
    ]


    for i, test_case in enumerate(test_cases, start=1):
        name = test_case.get("name")
        executable = test_case["executable"]
        args = test_case.get("args")
        expected_output = remove_color(test_case["expected_output"])


        # Format arguments if present
        if args is not None:
            args_str = " ".join(args)  # Convert arguments list to a single string
            name_with_args = f"{name}: ./{executable} {args_str}"  # Include arguments in the test case name
        else:
            name_with_args = f"{name}: ./{executable}"

        print(f"\n{i}.{name_with_args}   ", end="")
        result = run_c_program(executable, args)
    
        if check_output(remove_color(result.stderr), expected_output):
            print(f"{GREEN}\u2714{RESET}\n")
            print(f"{GREEN}{remove_color(result.stderr)}{RESET}\n")
        else:
            print(f"\n{RED}Test Failed: Output is incorrect.{RESET}")
            print(f"{YELLOW}Expected:{RESET}")
            print(expected_output)
            print(f"{YELLOW}Got:{RESET}")
            print(result.stderr)


if __name__ == "__main__":
    main()



