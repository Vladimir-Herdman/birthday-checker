#!/usr/bin/env bash

INSTALL_DIR="$HOME/.local/bin"

main() {
    if [[ -d "$INSTALL_DIR" ]]; then
        rm "$INSTALL_DIR/vh_bday"
    fi
}

main
