#include "render_data.h"

RenderData::RenderData() {
    resetData();
}

GLuint* RenderData::getVAO() {
    return &VAO;
}

GLuint* RenderData::getIndices() {
    return &indices;
}

void RenderData::resetData() {
    VAO = 0;
    indices = 0;
}

bool RenderData::hasVAO() {
    return VAO != 0;
}

bool RenderData::hasIndices() {
    return indices != 0;
}
