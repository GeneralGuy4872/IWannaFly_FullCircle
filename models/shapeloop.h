boneloop(subject)
  bone subject
  {
  if (subject.drawline)
    {
    shapeloop(shape_line(subject.len.x,subject.len.y,subject.len.z,subject.color,subject.ultraviolet)
    }
  shapeloop(subject.geom,subject.color,subject.ultraviolet)
  }

shapeloop(subject,color,ultra)
  shape subject
  truecolor color
  bool ultra
  {
  unsigned char n = 0 //for loops are not applicable here
  unsigned char mode = 0
  unsigned char iter = 0
  glColor4b((CAMERA->uv && PLAYER->stat.uv && ultra) ? 0xFF : color.r,(CAMERA->uv && PLAYER->stat.uv && ultra) ? 0 : color.g,(CAMERA->uv && PLAYER->stat.uv && ultra) ? 0xFF : color.b,(CAMERA->uv && PLAYER->stat.uv && ultra) ? 0x7F : color.a)
  while (n < subject.inum)
    {
    switch (mode)
      {
      case 0 :
        {
        mode = subject.bytecode[n]
        n++
        iter = subject.bytecode[n]
        n++
        break
        }
      case 1 :
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
        break
        }
      case 2 :
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
        break
        }
      case 3 :
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
        break
        }
      case 4 :
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
        break
        }
      case 5 :
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
        break
        }
      case 6 :
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
        break
        }
      case 7 :
        {
        glBegin(GL_TRIANGLE_FAN)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
          glCullFace(GL_BACK)
        glEnd()
        mode = 0
        break
        }
      case 8 :
        {
        glBegin(GL_LINE_LOOP)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        glEnd()
        mode = 0
        break
        }
      case 9 :
        {
        glBegin(GL_LINES)
          while (iter && (n < subject.inum))
            {
            glvertex3f(subject.vertlist[0].x,subject.vertlist[0].y,subject.vertlist[0].z)
            glvertex3f(subject.vertlist[subject.bytecode[n]].x,subject.vertlist[subject.bytecode[n]].y,subject.vertlist[subject.bytecode[n]].z)
            n++
            iter--
            }
        glEnd()
        mode = 0
        break
        }
      default :
        {
        while (iter && (n < subject.inum))
          {
          n++
          iter--
          }
        SOFT_ERROR_MACRO("GFX","shapeloop.h, line#"__LINE__", switch escape branch","Shapeloop recieved invalid opcode, could be a sign that the array being processed is not shape code for the current version of the shapeloop. If the sentrys are errant, this will raise SIGSEGV.")
        mode = 0
        break
        }
      }
    }
  }
