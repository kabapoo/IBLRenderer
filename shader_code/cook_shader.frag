#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

// light
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform float lightIntensity;
uniform int lightType;
// view
uniform vec3 viewPos;
// material
uniform vec3 materialColor;
uniform float materialFresnel;
uniform float materialRoughness;
uniform float materialSpecPower;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	//FragColor = mix(vec4(Normal, 1.0f), texture(texture2, TexCoord), 0.2);
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);

	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), materialGlossiness);
	vec3 specular = spec * lightColor;
	
	vec3 result = (diffuse + specular) * materialColor;

	FragColor = mix(vec4(result, 1.0f), texture(texture1, TexCoord), 0.0);
}