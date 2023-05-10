{ pkgs ? import <nixpkgs> {  } }:
pkgs.mkShell{

    name = "A Simle Shell";
    nativeBuildInputs = with pkgs; [
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

    shellHook = ''
        echo "Hi";
    '';
}
