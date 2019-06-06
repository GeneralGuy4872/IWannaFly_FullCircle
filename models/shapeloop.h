shapeloop(subject)
struct shape subject
  {
  unsigned char n = 0 //for loops are not applicable here
  unsigned char mode = 0
  unsigned char iter = 0
  glColor4b(subject.color.r,subject.color.g,subject.color.b,subject.color.a)
  while (n < subject.inum)
    {
    switch mode
      {
      case : 0
        {
        mode = subject.bytecode[n]
        n++
        iter = subject.bytecode[n]
        n++
        }
      case : 1
        {
        glBegin(GL_POINTS)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        glEnd()
        mode = 0
        }
      case : 2
        {
        glBegin(GL_LINES)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        glEnd()
        mode = 0
        }
      case : 3
        {
        glBegin(GL_TRIANGLES)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter0
            }
        glCullFace(GL_BACK)
        glEnd()
        mode = 0
        }
      case : 4
        {
        glBegin(GL_QUADS)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        glCullFace(GL_BACK)
        glEnd()
        mode = 0
        }
      case : 5
        {
        glBegin(GL_POLYGON)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        glEnd()
        mode = 0
        }
      case : 6
        {
        glBegin(GL_LINE_STRIP)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        glEnd()
        mode = 0
        }
      case : 7
        {
        glBegin(GL_TRIANGLE_FAN)
          while (iter && n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        glCullFace(GL_BACK)
        glEnd()
        mode = 0
        }
      case : 8
        {
        glBegin(GL_LINE_LOOP)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        mode = 0
        glEnd()
        }
      case : 9
        {
        glBegin(GL_LINES)
          while (iter && n < subject.inum))
            {
            glvertex3f(subject.vertlist[0].x,subject.vertlist[0].y,subject.vertlist[0].z)
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        glEnd()
        mode = 0
        }
      default
        {
        while (iter && (n < subject.inum))
          {
          n++
          iter--
          }
        SOFT_ERROR_MACRO("GFX","shapeloop.h, line#"__LINE__", switch escape branch","Shapeloop recieved invalid opcode, could be a sign that the array being processed is not shape code for the current version of the shapeloop. If the sentrys are errant as well, this will rais SIGSEGV.")
        mode = 0
        }
      }
    }
  }
