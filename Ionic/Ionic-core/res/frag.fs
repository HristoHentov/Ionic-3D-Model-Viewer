#version 330

layout (location = 0) out vec4 color;

in vec4 pos;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform vec2 mouse_pos;
uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

in DATA
{
	vec4 pos;
	vec3 col;
} fs_in;

struct Material
{
	sampler2D texture_diffuse1;
	sampler2D texture_specular1;
};

uniform Material material;

void main()
{
	/// Ambient Light Calculation
	float ambientIntensity = 0.1f;
	vec3 ambient =  vec3(texture(material.texture_diffuse1, TexCoord)) * 0.1 * lightColor;

	/// Diffuse Light Calculation
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * vec3(texture(material.texture_diffuse1, TexCoord)) * lightColor;

	/// Specular Light Calculation
	float specularIntensity = 2.8f;

	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128.0f);
	vec3 specular = spec * vec3(texture(material.texture_specular1, TexCoord)) * 1.8 * lightColor;  


	float i = 2 / length(fs_in.pos.xy - ((mouse_pos - vec2(256, 256)) / vec2(256, -256)));
	color = texture(ourTexture, TexCoord) * vec4((ambient + diffuse + specular), 1.0) * 3;
	//color = mix(texture(ourTexture, TexCoord), texture(ourTexture2, TexCoord), 0.3) * vec4(ambient, 1.0);
}