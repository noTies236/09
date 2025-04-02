#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>

class Shader
{
public:
    unsigned int ID;
    // Constructor: reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // Activate the shader
    void Use();

    // Utility uniform functions
    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void UpdateOffset();
};

#endif