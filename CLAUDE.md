# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

Personal competitive programming repository in C++. Contains problem solutions from various Online Judges and reusable algorithm templates. Notes are written in Chinese.

## Repository Structure

- `atcoder/` — AtCoder contest solutions (named by contest, e.g. `abc452d.cpp`)
- `luogu/` — Luogu solutions, organized into subdirectories: `P类/`, `B类/`, `GESP/`, `NOIP/`, `USACO/`, `U or T/`, `深基/`
- `accoders/` — Accoders platform solutions
- `Algorithm/` — Reusable algorithm templates (Dijkstra, segment tree, trie, knapsack variants, Euler path, etc.)
- `markdown笔记/` — Algorithm study notes in Chinese Markdown
- `python/` — Python scripts
- `vscode配置/` — VSCode configuration backups

## Build & Run

No build system (no Makefile/CMake). Each `.cpp` file is a standalone single-file solution compiled individually:

```bash
g++ -o sol P2491.cpp -std=c++17 -O2
./sol < input.txt
```

The CPH (Competitive Programming Helper) VSCode extension (`.cph-ng/`) is used for local test case management and auto-compilation.

## Code Conventions

- `#include <bits/stdc++.h>` and `using namespace std;` are standard
- `typedef long long ll;` is common
- Array sizes use `const int N = ...;` with generous padding
- Fast I/O: `ios::sync_with_stdio(false); cin.tie(nullptr);`
- Comments are in Chinese
- Filenames match problem IDs (e.g. `P2491.cpp`, `abc452d.cpp`)
- Solutions use competitive programming style: global arrays, short variable names, minimal abstraction
