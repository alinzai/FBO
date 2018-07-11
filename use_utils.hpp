#ifndef USE_UTILS_H
#define  USE_UTILS_H 1
#include <utility>

unsigned    createTexture(int width,int height);

std::pair<unsigned, unsigned> createFBO(int width, int height, unsigned textureId);



#endif 