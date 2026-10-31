# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo is

Teaching materials for the "Структури от данни и алгоритми" (Data Structures and Algorithms) course at FMI, Sofia University. It is not an application: there is no build system, package manifest, test suite or CI. Content is Markdown lecture notes (in **Bulgarian**), Jupyter playgrounds, and standalone C++/Python solutions to LeetCode/HackerRank problems. Write all README/prose content in Bulgarian, keeping English for problem titles, algorithm names and code.

Previous academic years live on branches (`2025-2026`, `2024-2025`); `main` is the current year. The root `README.md` links to them.

## Commands

- Python solutions are formatted with **black** (`black <file>`). Most are LeetCode `class Solution` snippets that rely on LeetCode's implicit imports (`List`, `Optional`, `ListNode`, `bisect`), so they don't run standalone — don't add a `main` or imports unless the file is a HackerRank-style stdin program.
- C++ files are compiled one at a time, e.g. `g++ -std=c++17 -Wall -Wextra file.cpp -o file` (the VS Code C/C++ Runner settings in `.vscode/` use g++/gdb with `-Wall -Wextra -Wpedantic -Wshadow -Wconversion ...`). Only files with `int main` (HackerRank-style, `all_sorts/`, `Examples/`, `Revision/`) are runnable; LeetCode `class Solution` files are not.
- Neither Python nor g++ is guaranteed on PATH on this machine; check before trying to run anything.

## Structure and placement rules

Top level: `README.md` (course index table), `Week_NN/`, `Exams/`.

```
Week_NN/
├── Seminar/
│   ├── README.md               # the seminar notes for the week
│   ├── playground_NN.ipynb     # in-class Python playground
│   ├── Solutions/
│   │   ├── README.md           # index of solved tasks, grouped by difficulty
│   │   ├── Easy/<ProblemName>/
│   │   ├── Medium/<ProblemName>/
│   │   ├── Hard/<ProblemName>/
│   │   └── Bonus/<ProblemName>/
│   └── <topic folders>         # e.g. all_sorts/, Implementations/, Examples/, images/
├── Practicum/
│   ├── Python/                 # README.md task list + "<LeetCode Title>.py" solutions
│   └── C++/                    # README.md task list (+ solutions)
└── Homework/TaskN/             # homework solutions, when there are any
Exams/
├── README.md                   # list of Seminar/Practicum exams with dates
└── Seminar/Exam_NN/            # README.md with the tasks + Solutions/TaskN/
```

### Week numbering and the root index
- Folders are `Week_01`, `Week_02`, … (two digits). Seminar READMEs start with `# Упражнение N`.
- Every new week, practicum, homework or exam must be added as a row/cell in the root `README.md` table (columns: Семинар, Практикум `[АД](Week_NN/Practicum/Python) \ [СИ](Week_NN/Practicum/C++)`, Домашно, Контролно). Practicum "АД" = Python stream, "СИ" = C++ stream. Exams are also listed in `Exams/README.md`.

### Seminar README
- Opens with a table of contents of the major themes (`## Темата включва` / `## Днес ще разгледаме`), each item a Markdown anchor link to a heading in the same file. When adding or renaming a heading, update the anchor (GitHub slug of the Bulgarian/English heading text, e.g. `#binary-search-двоично-търсене`).
- Code examples are given in both languages inside collapsible `<details><summary>C++</summary>` / `<details><summary>Python</summary>` blocks.
- Ends with `## Задачи` (optionally `### Подходи и съвети за задачи`), then `### Easy` / `### Medium` / (`### Hard`) problem lists as `- [Problem title](url)`, with optional nested hint bullets, then `# Бонус` / `## Бонус задачи`.
- A week may have an extra simplified variant (e.g. `Week_02/Seminar/Python_simple_README.md`) linked from the main README; keep its anchors consistent with the main one.

### Seminar Solutions
- One folder per problem under the difficulty bucket matching the seminar README's task list (Easy/Medium/Hard/Bonus). If a task moves difficulty in the README, move its folder too.
- Folder name = the problem's official title in PascalCase, matching the LeetCode slug (`DeleteNodeInALinkedList`, `Sqrtx`, `LinkedListCycle2` for "Linked List Cycle II"). HackerRank problems use their title (`Roommates`, `Puncakes`).
- File names: `c++_solution[_<approach>].cpp` and `py_solution[_<approach>].py`, where the suffix names the technique (`_iterative`, `_recursive`, `_two_pointers`, `_fast_slow`, `_counting`, `_quickselect`, …). Intentionally suboptimal versions are `c++_bad_solution_<approach>` / `py_bad_solution_<approach>` or `_slow`. (Week_01 uses the older `cpp_solution` prefix; new files use `c++_`.)
- First line of every solution is a comment with the problem URL (`// https://...` or `# https://...`), followed by a blank line. For LeetCode, keep the provided commented-out node definition (`ListNode`, etc.) as in the editor template.
- `Solutions/README.md` format: `# Решения - <тема>`, the line `Задачите са от [семинара](../README.md). Всяка папка съдържа решенията на C++ и/или Python.`, then `## Easy` / `## Medium` / `## Hard` / `## Bonus` with entries `- [Problem title](url) - [решения](./<Difficulty>/<ProblemName>)`. Add an entry whenever you add a solution folder.

### Practicum
- `Practicum/Python/`: `README.md` is `# Задачи` + list of `- [Title](url)` (optionally ` - Easy/Medium/Hard`); solution files are named exactly after the LeetCode title with spaces (`Merge Intervals.py`, `Sqrt(x).py`), may hold several `class Solution` variants separated by comments.
- `Practicum/C++/README.md`: `## Практикум №N по Структури от данни и алгоритми`, then `## Задачи в час` and further task sections.

### Exams
- `Exams/Seminar/Exam_NN/README.md` holds the exam statement (`# Контролно N СДА <year>`), tasks as `## Задача N: (X точки)`, code fragments shown in both C++ and Python.
- Solutions go in `Exams/Seminar/Exam_NN/Solutions/TaskN/` using the same `c++_solution_<approach>.cpp` / `py_solution_<approach>.py` naming.
