#include "texture_atlas.h"


TextureAtlas::TextureAtlas(const std::string &atlas) {
    loadTexture(atlas);
    //hardcode sizes for now
}

std::array<GLfloat, 8> TextureAtlas::getTexture(int x, int y) {
     GLfloat xMin = ((GLfloat)x * texture_size) + 0.5f * pixel_size;
        GLfloat yMin = ((GLfloat)y * texture_size) + 0.5f * pixel_size;

       GLfloat xMax = (xMin + texture_size) - pixel_size;
       GLfloat yMax = (yMin + texture_size) - pixel_size;

       return {xMax, yMax, xMin, yMax, xMin, yMin, xMax, yMin};
}
