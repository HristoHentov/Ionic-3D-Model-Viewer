#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoord;

uniform mat4 projection = mat4(1.0);
uniform mat4 view		= mat4(1.0);
uniform mat4 model		= mat4(1.0);

out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;
out DATA
{
	vec4 pos;
	vec3 col;

} vs_out;


void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0);
	vs_out.pos = projection * view * model * vec4(position, 1.0);
	vs_out.col = vec3(1.0, 1.0, 1.0);
	TexCoord = vec2(texCoord.x, 1.0f - texCoord.y);
	Normal = normal;
	FragPos = vec3(model * vec4(position, 1.0f));
}