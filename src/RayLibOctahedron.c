//Warning: contents may explode

Mesh GenMeshOcto(float width, float height, float length) {
    Mesh mesh = { 0 };
    mesh.vboId = (unsigned int *)RL_CALLOC(MAX_MESH_VBO, sizeof(unsigned int));

#define CUSTOM_MESH_GEN_OCTO
#if defined(CUSTOM_MESH_GEN_OCTO)
    float vertices[] = {
        0, 0, length/2,
        width/2, 0, 0,
        0, height/2, 0,

        0, 0, length/2,
        0, height/2, 0,
        -width/2, 0, 0,

        0, 0, length/2,
        -width/2, 0, 0,
        0, -height/2, 0,

        0, 0, length/2,
        0, -height/2, 0,
        width/2, 0, 0,

        width/2, 0, 0,
        0, height/2, 0,
        0, 0, -length/2,

        0, height/2, 0,
        -width/2, 0, 0,
        0, 0, -length/2,

        -width/2, 0, 0,
        0, -height/2, 0,
        0, 0, -length/2,

        0, -height/2, 0,
        width/2, 0, 0,
        0, 0, -length/2,
    };

    float texcoords[] = {
	0.0, 1.0,
	1.0, 1.0,
	0.5, 0.5,

	0.0, 1.0,
	0.5, 0.5,
	0.0, 0.0,

	0.0, 1.0,
	0.0, 0.0,
	0.5, 0.5,

	0.0, 1.0,
	0.5, 0.5,
	1.0, 1.0,

	1.0, 1.0,
	0.5, 0.5,
	1.0, 0.0,

	0.5, 0.5,
	0.0, 0.0,
	1.0, 0.0,

	0.0, 0.0,
	0.5, 0.5,
	1.0, 0.0,

	0.5, 0.5,
	1.0, 1.0,
	1.0, 0.0
    };

    float normals[] = {
         1.0f, 1.0f, 1.0f,
         1.0f, 1.0f, 1.0f,
         1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
         1.0f,-1.0f, 1.0f,
         1.0f,-1.0f, 1.0f,
         1.0f,-1.0f, 1.0f,
         1.0f, 1.0f,-1.0f,
         1.0f, 1.0f,-1.0f,
         1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
         1.0f,-1.0f,-1.0f,
         1.0f,-1.0f,-1.0f,
         1.0f,-1.0f,-1.0f,
    };

    mesh.vertices = (float *)RL_MALLOC(24*3*sizeof(float));
    memcpy(mesh.vertices, vertices, 24*3*sizeof(float));

    mesh.texcoords = (float *)RL_MALLOC(24*2*sizeof(float));
    memcpy(mesh.texcoords, texcoords, 24*2*sizeof(float));

    mesh.normals = (float *)RL_MALLOC(24*3*sizeof(float));
    memcpy(mesh.normals, normals, 24*3*sizeof(float));

    mesh.indices = (unsigned short *)RL_MALLOC(36*sizeof(unsigned short));

    int k = 0;

    // Indices can be initialized right now
    for (int i = 0; i < 36; i+=6)
    {
        mesh.indices[i] = 4*k;
        mesh.indices[i+1] = 4*k+1;
        mesh.indices[i+2] = 4*k+2;
        mesh.indices[i+3] = 4*k;
        mesh.indices[i+4] = 4*k+2;
        mesh.indices[i+5] = 4*k+3;

        k++;
    }

    mesh.vertexCount = 24;
    mesh.triangleCount = 8;
#else
    par_shapes_mesh *octo = par_shapes_create_octahedron();
    octo->tcoords = PAR_MALLOC(float, 2*octo->npoints);
    for (int i = 0; i < 2*octo->npoints; i++) octo->tcoords[i] = 0.0f;
    par_shapes_scale(octo, width, height, length);
    par_shapes_translate(octo, -width/2, 0.0f, -length/2);
    par_shapes_compute_normals(octo);

    mesh.vertices = (float *)RL_MALLOC(octo->ntriangles*3*3*sizeof(float));
    mesh.texcoords = (float *)RL_MALLOC(octo->ntriangles*3*2*sizeof(float));
    mesh.normals = (float *)RL_MALLOC(octo->ntriangles*3*3*sizeof(float));

    mesh.vertexCount = octo->ntriangles*3;
    mesh.triangleCount = octo->ntriangles;

    for (int k = 0; k < mesh.vertexCount; k++)
    {
        mesh.vertices[k*3] = octo->points[cube->triangles[k]*3];
        mesh.vertices[k*3 + 1] = octo->points[cube->triangles[k]*3 + 1];
        mesh.vertices[k*3 + 2] = octo->points[cube->triangles[k]*3 + 2];

        mesh.normals[k*3] = octo->normals[cube->triangles[k]*3];
        mesh.normals[k*3 + 1] = octo->normals[cube->triangles[k]*3 + 1];
        mesh.normals[k*3 + 2] = octo->normals[cube->triangles[k]*3 + 2];

        mesh.texcoords[k*2] = octo->tcoords[cube->triangles[k]*2];
        mesh.texcoords[k*2 + 1] = octo->tcoords[cube->triangles[k]*2 + 1];
    }

    par_shapes_free_mesh(octo);
#endif

    // Upload vertex data to GPU (static mesh)
    rlLoadMesh(&mesh, false);

    return mesh;
}
