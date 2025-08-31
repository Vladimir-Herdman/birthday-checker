#!/usr/bin/env bash

source "$(dirname "$0")/globals.sh"

main() {
    if [[ -d "$INSTALL_DIR" ]]; then
        rm "$INSTALL_DIR/$BINARY_NAME"
    fi
}

main
