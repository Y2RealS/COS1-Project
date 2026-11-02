# Version Control & Markdown Documentation

**Course:** COS1  
**Name:** Bengaly Prince Cisse  
**Date:** November 1, 2026  

---

## 1. What is Version Control?
Version control is a system that records changes to a file or set of files over time so that specific versions can be recalled later. It allows developers to track revisions, revert to previous code states, and collaborate safely without overwriting each other's work.

## 2. Comparing Version Control Systems

### Local Version Control
- **Description:** Manually copying files into backup folders or appending version numbers to filenames.
- **Pros:** Simple and requires no network setup.
- **Cons:** High risk of human error, accidental file deletion, and file corruption.

### Centralized Version Control (CVCS)
- **Description:** A single central server stores all versioned files, and clients check out code directly from that server (e.g., Subversion, Perforce).
- **Pros:** Centralized administration and clear visibility into who is working on specific files.
- **Cons:** Single point of failure; if the server goes down or crashes without backups, project history is lost.

### Distributed Version Control (DVCS)
- **Description:** Every developer clones a full copy of the complete repository, including its history, onto their local machine (e.g., Git).
- **Pros:** Full offline access, redundant local backups if the central server fails, and flexible branching workflows.
- **Cons:** Slightly steeper learning curve and larger initial clone size for massive projects.

## 3. Essential Git Commands & Definitions
- **`git init`**: Initializes a new local Git repository in the current directory.
- **`git clone <url>`**: Copies an existing remote repository onto your local machine.
- **`git status`**: Shows the working tree status, including staged, unstaged, and untracked files.
- **`git add <file>`**: Adds file changes from the working directory to the staging area.
- **`git commit -m "message"`**: Records staged changes to the repository history with a descriptive log message.
- **`git push`**: Uploads local repository commits to a remote repository (e.g., GitHub).
- **`git pull`**: Fetches and merges changes from a remote repository into the current local branch.

---

## References
- Git Documentation: https://git-scm.com/doc
- Markdown Guide: https://www.markdownguide.org
