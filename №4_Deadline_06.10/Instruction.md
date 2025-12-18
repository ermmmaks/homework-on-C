## Instruction

To build this application, run

```console
$ gcc main.c optSort.s -Wall -Wextra -Wpedantic -O2 -o main
```

optSort.c was compiled into optSort.s with 

```console
$ gcc optSort.c -S -O2 -Wall -Wextra -Wpedantic -o optSort.s
```

Use this comand to see count of moved elements
```console
echo$?
```