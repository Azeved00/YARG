{ pkgs ? import <nixpkgs> {  } }:
let
    root = builtins.getEnv "PWD";
in pkgs.mkShell{
    name = "Game Development";
    buildInputs = with pkgs; [
        gnumake
        alsaLib
        mesa
        xorg.libX11
        xorg.libXft
        xorg.libXinerama
        xorg.libXrandr
        xorg.libXi
        xorg.libXcursor
        xorg.xorgserver
        mesa
        mesa_glu
        raylib
    ];
    ROOT=root;

    shellHook = ''
        echo -ne "\033]0;Game Development\007"

        alias build='gcc -o $ROOT/game.bin -Wall $ROOT/src/main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -latomic'
        
        alias run='$ROOT/game.bin'
    '';
}
