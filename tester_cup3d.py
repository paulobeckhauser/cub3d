import subprocess
import re
import glob


# Define ANSI color codes
RED = "\033[1;31m"
GREEN = "\033[1;32m"
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


    # if use_valgrind:
    #     run_command = ["valgrind", "--leak-check=full", "--error-exitcode=1"] + run_command


    result = subprocess.run(run_command, capture_output=True, text=True)
    return result


def check_output(output, expected_output):
    return output == expected_output

# def check_valgrind_output(valgrind_output):
#     # Check if Valgrind detected any errors
#     if "ERROR SUMMARY: 0 errors from 0 contexts" in valgrind_output:
#         return True
#     return False


def main():

    if not run_make("re"):
        return

    print("\nCompiled with sucess")



    test_cases_error = []
    test_cases_correct = []

    map_files_errors = glob.glob('maps/errors/*')
    map_files_correct = glob.glob('maps/correct/*')

    for map_file_error in map_files_errors:
        test_cases_error.append({"args": [map_file_error]})

    for map_file_correct in map_files_correct:
        test_cases_correct.append({"args": [map_file_correct]})

    print("\n\n\nTest errors maps:")
    for i, test_case_error in enumerate(test_cases_error, start=1):
        executable = "cub3d"
        args = test_case_error.get("args")
        expected_output = "Error"

        result = run_c_program(executable, args)
        result_error = remove_color(result.stderr.split('\n')[0])
        if check_output(result_error, expected_output):
            print(f"{GREEN}{i}.", end="")
            print(f"✅[OK]{RESET}", end="")
        else:
            print(f"{RED}\n{i}.", end="")
            print(f"\u274C", end="")
            print(f"The execution was: ./{executable} {args[0]}{RESET}")


        # # Run with Valgrind
        # valgrind_result = run_c_program(executable, args, use_valgrind=True)
        # if check_valgrind_output(valgrind_result.stderr):
        #     print(f" {GREEN}[Valgrind: OK]{RESET}", end="")
        # else:
        #     print(f" {RED}[Valgrind: Memory Leak]{RESET}", end="")

    print("\n\nTest correct maps:")
    for i, test_case_correct in enumerate(test_cases_correct, start=1):
        executable = "cub3d"
        args = test_case_correct.get("args")
        expected_output = ""

        result = run_c_program(executable, args)
        result_error = remove_color(result.stderr.split('\n')[0])
        if check_output(result_error, expected_output):
            print(f"{GREEN}{i}.", end="")
            print(f"✅[OK]{RESET}", end="")
        else:
            print(f"{RED}\n{i}.", end="")
            print(f"\u274C", end="")
            print(f"The execution was: ./{executable} {args[0]}{RESET}")
    


# def check_valgrind:
#     valgrind = 'valgrind --leak-check=full'
#     dir = '/tester_maps/'
#     cmds = ['./cub3d {dir}map1.cub', './cub3d {dir}asd']
#     for c in


if __name__ == "__main__":
    main()
    print("\n")

