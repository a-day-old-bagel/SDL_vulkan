{ SDL2, cmake, pkgconfig, stdenv, vulkan-loader }: stdenv.mkDerivation {
  name = "SDL_vulkan-0.1.0";
  src = ./.;
  buildInputs = [ cmake pkgconfig SDL2 vulkan-loader ];
  meta = {
    license = stdenv.lib.licenses.mit;
  };
}
