# Milestone 3 Changelog - Project Rover

## ⚙️ Features Added
- **Player Power Allocation System:** Implemented a resource distribution mechanic allowing players to allocate points to weapons or shields during their turn (`Player::allocatePower`).
- **Robust Input Validation:** Replaced raw `std::cin` with a safe input helper using `std::getline` and `std::stoi` to prevent console crashes on invalid character inputs.

## 🧱 Updates to System Design
- Expanded the class-based architecture (`GameManager`, `Player`, `Enemy`) to handle state changes and resource pooling cleanly.
- Properly scoped class member functions and data variables across header and source files (`.h` and `.cpp`).

## 🧹 Refactoring Improvements
- **Resolved Compilation Errors:** Cleaned up header definitions, fixed scope resolution issues for member functions, and ensured parameters matched between declarations and definitions.
- **Variable Declaration Cleanup:** Properly initialized and encapsulated member variables like `weaponPower` and `shieldPower` inside the `Player` class private blocks.
- **Control Flow Stability:** Improved menu prompt loops and error handling to ensure predictable console execution.

## 💭 What Changed and Why
- *Moved input logic and validation:* Implemented safeguards around user choices so typing letters or symbols won't break the game loop, making the application much more robust for testing.
- *Structured player progression systems:* Added localized power mechanics to lay the foundation for tactical depth in upcoming milestones without bloating the main game loop.
