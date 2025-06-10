# 🧠 Plagiarism Detector 🔍

A C-based command-line tool that detects textual plagiarism using techniques such as **n-gram analysis**, **Rabin-Karp string matching**, and **cosine similarity**.

---

## 📁 Project Structure

```text
plagiarism_detector/
├── build/                    # Compiled object files and executables
├── data/                     # Input documents for plagiarism detection
│   ├── document1.txt
│   └── document2.txt
├── include/                  # Header files
│   ├── cosine_similarity.h
│   ├── file_io.h
│   ├── ngram.h
│   ├── preprocessing.h
│   └── rabin_karp.h
├── src/                      # Source code
│   ├── cosine_similarity.c
│   ├── file_io.c
│   ├── main.c
│   ├── ngram.c
│   ├── preprocessing.c
│   └── rabin_karp.c
├── plagiarism_detector.exe   # Compiled executable (for Windows)
└── compile.sh                # Shell script to compile the project

🚀 Features
Reads two text documents and detects similarities.
Supports the following algorithms:
N-gram analysis
Cosine similarity
Rabin-Karp string matching

Classifies similarity levels as:
🔹 Minimal
🔸 Low
🔶 Moderate
🔴 High

🛠️ How to Compile
Linux / WSL
Give execution permission and run the shell script:
chmod +x compile.sh
./compile.sh

Alternatively, compile manually using gcc:
gcc src/*.c -Iinclude -o plagiarism_detector.exe

✅ Requirements:
GCC (or any C compiler)
Bash (for compile.sh)
A terminal environment (Linux, WSL, or Git Bash on Windows)

📄 Sample Output
==== PLAGIARISM DETECTION REPORT ====

==== Similarity Score: 0.76 (76.00%)
Matching n-grams: 38 out of 50
Interpretation: MODERATE SIMILARITY (76.00%)
There may be some copied content or similar phrasing.

📜 License
This project is licensed under the MIT License — feel free to use, modify, and share!

🤝 Contributing
Pull requests are welcome!
For major changes, please open an issue first to discuss what you'd like to change.

🙋‍♂️ Author
Made with 💻 by Arnav Mishra

---

Let me know if you want:
- A version with screenshots.
- To add instructions for **Windows compilation** using an IDE.
- Badges (e.g., build status, license, etc.).
- Or anything else!
