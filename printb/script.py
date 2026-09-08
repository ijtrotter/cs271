import os

codes = ['d','i','o','u','x','e','f','g','s','c','p','n']

for code in codes:
    output = f"""#include <stdio.h>

int main() {{
    printf("code {code} = %{code}\\n", 1 == 1);
    return 0;
}}"""

    with open("output.c", "w") as f:
        f.write(output)

    os.system("gcc output.c --std=c89 -Wall -Wextra -Werror -Wpedantic -O2")
    #os.system("gcc output.c")
    os.system("./a.out")
