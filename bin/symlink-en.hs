#!/usr/bin/env bash
# -----------------------------------------------------------------------------
# Genera, dentro src/cpp-en/, un symlink placeholder per ogni file di
# src/cpp-it/ che non sia già stato tradotto per davvero.
# Da rilanciare (è idempotente) ogni volta che serve, finché la traduzione
# non è completa: i simlink dei file già tradotti vengono saltati.
# -----------------------------------------------------------------------------
set -euo pipefail

cd "$(dirname "$0")/.."   # spostati alla radice del progetto, se lanciato da bin/

SRC_IT="src/cpp-it"
SRC_EN="src/cpp-en"

if [ ! -d "$SRC_IT" ]; then
    echo "Errore: $SRC_IT non trovato. Hai già rinominato src/cpp in src/cpp-it?" >&2
    exit 1
fi

mkdir -p "$SRC_EN"

CREATI=0
SALTATI=0

for file_it in "$SRC_IT"/*; do
    nome=$(basename "$file_it")
    target="$SRC_EN/$nome"

    if [ -e "$target" ] || [ -L "$target" ]; then
        # esiste già (file tradotto per davvero, o symlink già fatto in precedenza)
        SALTATI=$((SALTATI + 1))
        continue
    fi

    ln -s "../cpp-it/$nome" "$target"
    CREATI=$((CREATI + 1))
done

echo "Symlink placeholder creati: $CREATI"
echo "File già presenti (saltati): $SALTATI"
