#!/usr/bin/env bash
# This script is intended for a UNIX based system.  If you're raw windows, consider
# WSL, or compile and figure it out path-wise.  Same goes for the other scripts here

INSTALL_DIR="$HOME/.local/bin"

get_root_dir_path() {
    local root_dir; root_dir=$(pwd)
    if [[ $(basename "$root_dir") != 'birthday_checker' ]]; then
        root_dir="${root_dir%%"birthday_checker"*}birthday_checker"
    fi
    printf "%s" "$root_dir"
}

main() {
    if [[ -d "$INSTALL_DIR" ]]; then
        true;
    else
        printf "%s\n" "  Creating directory to store binary locally at: $INSTALL_DIR"
        mkdir -p "$INSTALL_DIR"
    fi

    local root_dir; root_dir="$(get_root_dir_path)"
    cd "$root_dir" || return

    printf "%s\n" "  Copying binary to installation directory at: $INSTALL_DIR/vh_bday"
    cp -f ./bin/main "$INSTALL_DIR/vh_bday"

    if [[ ":$PATH:" == *":$INSTALL_DIR:"* ]]; then
        printf "%s\n" "  You may now call 'vh_bday' to use this script"
    else
        local current_shell; current_shell="$SHELL"
        if [[ "$current_shell" == *'zsh'* ]]; then
            printf "%s\n" "  Adding path export to shell configuration file: $HOME/.zshrc"
            printf "%s%s" 'export PATH=$PATH:' "$INSTALL_DIR" >> "$HOME/.zshrc"
            printf "%s\n" "  You may now call 'vh_bday' to use this script, but open a new shell instance first"
        elif [[ "$current_shell" == *'bash'* ]]; then
            printf "%s\n" "  Adding path export to shell configuration file: $HOME/.bashrc"
            printf "%s%s" 'export PATH=$PATH:' "$INSTALL_DIR" >> "$HOME/.bashrc"
            printf "%s\n" "  You may now call 'vh_bday' to use this script, but open a new shell instance first"
        else
            printf "%s\n" "  Add '$INSTALL_DIR' directory to shell PATH in order to use script"
        fi
    fi
}

main
