const char* SimpleFragmentShader = STRINGIFY(

varying lowp vec4 DestinationColor;

varying lowp vec2 TexCoordOut;
uniform sampler2D Texture;
varying mediump vec2 TextureSize;
void main(void)
{
    gl_FragColor =  texture2D(Texture, TexCoordOut);//DestinationColor;    
}
);
