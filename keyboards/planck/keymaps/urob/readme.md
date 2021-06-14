## Keymap configuration for OLKB Planck

- layout based on Miryoku
- dual purpose keys on home row and thumbs for modifiers and to switch layers
- repeat key on right home thumb to reduce SFUs
- delete on shift-bspc
- caps word when both shifts are pressed together
- unicode layer with greek symbols for mathematical typesetting (shifted
  versions when both layer modifiers are pressed together)
- symbols and desktop shortcuts can be reached from the base layer via combos
- the middle two columns do nothing (except for a num lock on row 1)
- the bottom left key is mapped to undo/redo (can be bumped with palm with hands on the home row)
- the bottom right two keys are mouse wheel up/down for hands-off-keyboard browsing and for advancing slides in presentations

![](layout.png)

## Combos

- the arrangement is optimized for mathematical coding and typesetting with
  latex
- vertical top row symbols follow mostly the standard num row arrangement
  (except + and & being swapped)
- vertical bottom row symbols are arranged to match the top row for easier
  memorization (superscript ^ and subscript _; + and -, * and
  /; logical operators & and |)
- holding down both index fingers (t + n) activates caps word (a smart caps lock
  that deactivates itself at the end of the word)

## Requirements

The configuration requires the following commits merged into the local QMK
branch. All requirements are satisfied when forking this branch

- Bilateral combinations branch
- Early combination branch
