# Plagiarism Detector 🔍

A C-based command-line tool that detects textual plagiarism using techniques like n-gram comparison, Rabin-Karp string matching, and cosine similarity.

## 📁 Project Structure

plagiarism_detector/
├── build/ # Compiled object files and executables
├── data/ # Input documents for plagiarism detection
│ ├── document1.txt
│ └── document2.txt
├── include/ # Header files
│ ├── cosine_similarity.h
│ ├── file_io.h
│ ├── ngram.h
│ ├── preprocessing.h
│ └── rabin_karp.h
├── src/ # Source code
│ ├── cosine_similarity.c
│ ├── file_io.c
│ ├── main.c
│ ├── ngram.c
│ ├── preprocessing.c
│ └── rabin_karp.c
├── plagiarism_detector.exe # Compiled executable (Windows)
└── compile.sh # Shell script to compile the project
---

## 🚀 Features

- Reads two text documents and detects similarities.
- Uses:
  - **N-gram analysis**
  - **Cosine similarity**
  - **Rabin-Karp string matching**
- Classifies similarity as:
  - Minimal
  - Low
  - Moderate
  - High

---

## 🛠️ How to Compile

### Linux / WSL
chmod +x compile.sh
./compile.sh

You can also use gcc directly:
gcc src/*.c -Iinclude -o plagiarism_detector.exe
📄 Sample Output
==== PLAGIARISM DETECTION REPORT ====
Similarity Score: 0.76 (76.00%)
Matching n-grams: 38 out of 50

Interpretation:
MODERATE SIMILARITY (76.00%): There may be some copied content or similar phrasing.
📚 Requirements
GCC (or any C compiler)

Bash (for compile.sh)

A terminal environment (Linux, WSL, or Git Bash on Windows)

🔓 License
This project is licensed under the MIT License. Feel free to use, modify, and share!

🤝 Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you’d like to change.
