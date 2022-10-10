# f4_anto

Ryan's Layer but with a modal keybinding system made to suit my needs and make me happy.

- It is somewhat similar to vim but lacks many bindings and functionality, such as concatenated keystrokes (ej. `diw`, `ci"`, `10j`).
- The only indicator of the current mode is the cursor color.
- The `4ed.exe` binary has been patched to not crash on certain nvidia graphics cards and the intel integrated cpu on my laptop. This was possible due to the open sourcing of 4coder, which means that 4.1.8 was the last offical core version from Allen and his contributors. Hopefully one day Allen comes back with a similar but bigger and better text editor from Dion Systems.
- Has variables that loads at startup from `theme-name.4coder` files and `config.4coder` to configure cursor properties.
