# Milestone 3 Changelog & Documentation

## ⚙️ Features Added
- Expanded the core turn-based combat loop inside `GameManager` to support dynamic enemy state tracking and active player/enemy health calculations.
- Integrated structured data management using vectors and object-oriented class interactions across `Player`, `Enemy`, and `GameManager`.

## 🧱 Updates to System Design
- Reorganized class responsibilities by separating core game flow logic from individual entity attributes (`Player` and `Enemy` header/source files).
- Standardized project architecture to ensure smooth compilation and clean state transitions between the main menu and active combat loops in Visual Studio.

## 🧹 Refactoring Improvements
- Reviewed input handling across menu screens to prepare for extracting raw console input checks into dedicated utility helpers.
- Cleaned up duplicate code blocks inside the battle loop by streamlining damage calculations and turn progression logic.

## 💭 What I Changed and Why
- **What Changed:** Moved direct stats handling and initialization out of `main.cpp` and structured them cleanly within class constructors and dedicated methods.
- **Why:** This ensures `main.cpp` acts purely as an entry point, making the project easier to debug, maintain, and expand as new tactical features are introduced in future milestones.
