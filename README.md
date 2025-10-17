Sudoku NumWorks Epsilon App (Comprehensive Source)
=================================================

Features included in these sources:
- 9x9 Sudoku engine (presets + placeholder generator)
- Easy / Hard difficulty presets
- Dark mode support (GridView::setDark)
- Basic navigation and event handling (arrow keys, OK toggles hint)
- Storage placeholders to persist progress
- GitHub Actions workflow provided to build .nwa automatically

How to build
1. Clone Epsilon SDK: git clone https://github.com/numworks/epsilon.git
2. Copy this folder into epsilon/apps/sudoku
3. Add 'sudoku' to the APPS list in apps/Makefile
4. Use the SDK build: make PLATFORM=n0110 nwa
5. The .nwa will appear in output/release/n0110/

Notes
- Some Escher/SDK functions are placeholders and may require adaptation to your SDK version.
- If you want, paste compilation errors here and I will update the sources to fix them.