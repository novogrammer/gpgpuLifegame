#version 150

uniform sampler2DRect tex0;
uniform vec2 mouse;
uniform bool pressed;
uniform float range;
uniform vec2 cellsize;

in vec2 varyingposition;
in vec2 varyingtexcoord;

out vec4 outputColor;
void main(){
    float d=distance(mouse,varyingposition);
    if(d<=range){
        outputColor=vec4(1.0f,1.0f,1.0f,1.0f);
    }else{
        if(pressed){
            outputColor=texture(tex0,varyingtexcoord);
        }else{
            float life=texture(tex0,varyingtexcoord).r;
            float count=0;
            for(int y=-1;y<=1;++y){
                for(int x=-1;x<=1;++x){
                    count+=texture(tex0,mod(varyingtexcoord+vec2(x,y),cellsize)).r;
                }
            }
            float nextLife=0.0f;
            if(life==0.0f){
                if(count==3.0f){
                    nextLife=1.0f;
                }
            }else{
                if(3.0f<=count && count<=4.0f){
                    nextLife=1.0f;
                }
            }
            outputColor=vec4(nextLife,nextLife,nextLife,1.0f);
        }
    }
}