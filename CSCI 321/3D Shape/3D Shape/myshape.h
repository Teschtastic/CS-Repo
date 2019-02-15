

// Change this line to point to your texture file.  One only.
#define MYTEXTUREFILE "smile.png"


GLuint object;


void GenerateShape()
{
    object = glGenLists(1);
    
    glNewList( object, GL_COMPILE );
    
    // Top Pyramid
    glBegin(GL_TRIANGLES);
    
    // Front
    glTexCoord2f(0.375,0);  glVertex3f(0,1.5,0);        // top
    glTexCoord2f(0.25,1);   glVertex3f(-0.5,0.5,0.5);   // bottom left
    glTexCoord2f(0.5,1);    glVertex3f(0.5,0.5,0.5);    // bottom right
    
    // right
    glTexCoord2f(0.375,0);  glVertex3f(0,1.5,0);        // top
    glTexCoord2f(0.25,1);   glVertex3f(0.5,0.5,0.5);    // bottom left
    glTexCoord2f(0.5,1);    glVertex3f(0.5,0.5,-0.5);   // bottom right
    
    // back
    glTexCoord2f(0.375,0);  glVertex3f(0,1.5,0);        // top
    glTexCoord2f(0.25,1);   glVertex3f(0.5,0.5,-0.5);   // bottom left
    glTexCoord2f(0.5,1);    glVertex3f(-0.5,0.5,-0.5);  // bottom right
    
    // left
    glTexCoord2f(0.375,0);  glVertex3f(0,1.5,0);        // top
    glTexCoord2f(0.25,1);   glVertex3f(-0.5,0.5,-0.5);  // bottom left
    glTexCoord2f(0.5,1);    glVertex3f(-0.5,0.5,0.5);   // bottom right
    
    glEnd();
    
    // Cube
    glBegin(GL_QUADS);
    
    // Front
    glTexCoord2f(0,0);      glVertex3f(-0.5,0.5,0.5);    // top left
    glTexCoord2f(0,1);      glVertex3f(-0.5,-0.5,0.5);   // bottom left
    glTexCoord2f(0.25,1);   glVertex3f(0.5,-0.5,0.5);    // bottom right
    glTexCoord2f(0.25,0);   glVertex3f(0.5,0.5,0.5);     // top right
    
    // Back
    glTexCoord2f(0,0);      glVertex3f(0.5,0.5,-0.5);    // top left
    glTexCoord2f(0,1);      glVertex3f(0.5,-0.5,-0.5);   // bottom left
    glTexCoord2f(0.25,1);   glVertex3f(-0.5,-0.5,-0.5);  // bottom right
    glTexCoord2f(0.25,0);   glVertex3f(-0.5,0.5,-0.5);   // top right
    
    // Left
    glTexCoord2f(0,0);      glVertex3f(-0.5,0.5,-0.5);   // top left
    glTexCoord2f(0,1);      glVertex3f(-0.5,-0.5,-0.5);  // bottom left
    glTexCoord2f(0.25,1);   glVertex3f(-0.5,-0.5,0.5);   // bottom right
    glTexCoord2f(0.25,0);   glVertex3f(-0.5,0.5,0.5);    // top right

    // Right
    glTexCoord2f(0,0);      glVertex3f(0.5,0.5,0.5);     // top left
    glTexCoord2f(0,1);      glVertex3f(0.5,-0.5,0.5);    // bottom left
    glTexCoord2f(0.25,1);   glVertex3f(0.5,-0.5,-0.5);   // bottom right
    glTexCoord2f(0.25,0);   glVertex3f(0.5,0.5,-0.5);    // top right

    glEnd( );
    
    // Bottom Thingy
    glBegin(GL_QUADS);
    
    // Front
    glTexCoord2f(0.75,0); glVertex3f(-0.5,-0.5,0.5);    // top left
    glTexCoord2f(0.75,1); glVertex3f(-0.75,-1,1);   // bottom left
    glTexCoord2f(1,1); glVertex3f(0.75,-1,1);    // bottom right
    glTexCoord2f(1,0); glVertex3f(0.5,-0.5,0.5);     // top right
    
    // right
    glTexCoord2f(0.75,0); glVertex3f(0.5,-0.5,0.5);    // top left
    glTexCoord2f(0.75,1); glVertex3f(0.75,-1,1);   // bottom left
    glTexCoord2f(1,1); glVertex3f(0.75,-1,-1);    // bottom right
    glTexCoord2f(1,0); glVertex3f(0.5,-0.5,-0.5);     // top right
    
    // back
    glTexCoord2f(0.75,0); glVertex3f(0.5,-0.5,-0.5);    // top left
    glTexCoord2f(0.75,1); glVertex3f(0.75,-1,-1);   // bottom left
    glTexCoord2f(1,1); glVertex3f(-0.75,-1,-1);    // bottom right
    glTexCoord2f(1,0); glVertex3f(-0.5,-0.5,-0.5);     // top right
    
    // left
    glTexCoord2f(0.75,0); glVertex3f(-0.5,-0.5,-0.5);    // top left
    glTexCoord2f(0.75,1); glVertex3f(-0.75,-1,-1);   // bottom left
    glTexCoord2f(1,1); glVertex3f(-0.75,-1,1);    // bottom right
    glTexCoord2f(1,0); glVertex3f(-0.5,-0.5,0.5);     // top right
    
    // bottom
    glTexCoord2f(0.5,0); glVertex3f(-0.75,-1,1);    // top left
    glTexCoord2f(0.5,1); glVertex3f(-0.75,-1,-1);   // bottom left
    glTexCoord2f(0.75,1); glVertex3f(0.75,-1,-1);    // bottom right
    glTexCoord2f(0.75,0); glVertex3f(0.75,-1,1);     // top right
    
    
    glEnd();
    
    glEndList( );
}
