//
// Created by hobbang5 on 2015-11-09.
//


#include "basicgles.h"
#include "gl_texture_util.h"
#include "gl_utils.h"

ELEMENTARY_GLVIEW_GLOBAL_DEFINE();

const float cube_vertices[] =
        {
                -0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f, 0.5f,
                0.5f, -0.5f, 0.5f,
                0.5f, -0.5f, -0.5f,
                -0.5f, 0.5f, -0.5f,
                -0.5f, 0.5f, 0.5f,
                0.5f, 0.5f, 0.5f,
                0.5f, 0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,
                -0.5f, 0.5f, -0.5f,
                0.5f, 0.5f, -0.5f,
                0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f, 0.5f,
                -0.5f, 0.5f, 0.5f,
                0.5f, 0.5f, 0.5f,
                0.5f, -0.5f, 0.5f,
                -0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f, 0.5f,
                -0.5f, 0.5f, 0.5f,
                -0.5f, 0.5f, -0.5f,
                0.5f, -0.5f, -0.5f,
                0.5f, -0.5f, 0.5f,
                0.5f, 0.5f, 0.5f,
                0.5f, 0.5f, -0.5f
        };

const int cube_indices_count = 36;
const unsigned short cube_indices[] =
        {
                0, 2, 1,
                0, 3, 2,
                4, 5, 6,
                4, 6, 7,
                8, 9, 10,
                8, 10, 11,
                12, 15, 14,
                12, 14, 13,
                16, 17, 18,
                16, 18, 19,
                20, 23, 22,
                20, 22, 21
        };

const float cube_colors[] =
        {
                0.996, 0.0, 0.498, 1.0,
                0.996, 0.0, 0.498, 1.0,
                0.996, 0.0, 0.498, 1.0,
                0.996, 0.0, 0.498, 1.0,
                0.468, 0.792, 0.361, 1.0,
                0.468, 0.792, 0.361, 1.0,
                0.468, 0.792, 0.361, 1.0,
                0.468, 0.792, 0.361, 1.0,
                0.604, 0.859, 0.937, 1.0,
                0.604, 0.859, 0.937, 1.0,
                0.604, 0.859, 0.937, 1.0,
                0.604, 0.859, 0.937, 1.0,
                0.769, 0.788, 0.945, 1.0,
                0.769, 0.788, 0.945, 1.0,
                0.769, 0.788, 0.945, 1.0,
                0.769, 0.788, 0.945, 1.0,
                1.0, 0.980, 0.184, 1.0,
                1.0, 0.980, 0.184, 1.0,
                1.0, 0.980, 0.184, 1.0,
                1.0, 0.980, 0.184, 1.0,
                1.0, 0.773, 0.553, 1.0,
                1.0, 0.773, 0.553, 1.0,
                1.0, 0.773, 0.553, 1.0,
                1.0, 0.773, 0.553, 1.0
        };

const float cube_texs[] =
        {
                0.0, 0.0,
                1.0, 0.0,
                1.0, 1.0,
                0.0, 1.0,
                0.0, 0.0,
                1.0, 0.0,
                1.0, 1.0,
                0.0, 1.0,
                0.0, 0.0,
                1.0, 0.0,
                1.0, 1.0,
                0.0, 1.0,
                0.0, 0.0,
                1.0, 0.0,
                1.0, 1.0,
                0.0, 1.0,
                0.0, 0.0,
                1.0, 0.0,
                1.0, 1.0,
                0.0, 1.0,
                0.0, 0.0,
                1.0, 0.0,
                1.0, 1.0,
                0.0, 1.0
        };



/*
const float cube_colors[] =
        {
                1.0, 0.0, 0.0, 1.0,
                0.0, 1.0, 0.0, 1.0,
                0.0, 0.0, 1.0, 1.0,
                1.0, 0.0, 0.0, 1.0,
                0.0, 1.0, 0.0, 1.0,
                0.0, 0.0, 1.0, 1.0,
                1.0, 0.0, 0.0, 1.0,
                0.0, 1.0, 0.0, 1.0,
                0.0, 0.0, 1.0, 1.0,
                1.0, 0.0, 0.0, 1.0,
                0.0, 1.0, 0.0, 1.0,
                0.0, 0.0, 1.0, 1.0,
                1.0, 0.0, 0.0, 1.0,
                0.0, 1.0, 0.0, 1.0,
                0.0, 0.0, 1.0, 1.0,
                1.0, 0.0, 0.0, 1.0,
                0.0, 1.0, 0.0, 1.0,
                0.0, 0.0, 1.0, 1.0,
                1.0, 0.0, 0.0, 1.0,
                0.0, 1.0, 0.0, 1.0,
                0.0, 0.0, 1.0, 1.0,
                1.0, 0.0, 0.0, 1.0,
                0.0, 1.0, 0.0, 1.0,
                0.0, 0.0, 1.0, 1.0
        };
        */

/* Vertex Shader Source */
static const char vertex_shader[] =
        "uniform mat4 u_wvpMatrix;\n"
                "attribute vec4 a_position;\n"
                "attribute vec4 a_color;\n"
                "varying vec4 v_color;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    v_color = a_color;\n"
                "    gl_Position = u_wvpMatrix * a_position;\n"
                "}";

/* Fragment Shader Source */
static const char fragment_shader[] =
        "#ifdef GL_ES\n"
                "precision mediump float;\n"
                "#endif\n"
                "varying vec4 v_color;\n"
                "\n"
                "void main (void)\n"
                "{\n"
                "    gl_FragColor = v_color;\n"
                "}";


/* Vertex Shader texture Source */
static const char vertex_tex_shader[] =
        "uniform mat4 u_wvpMatrix;\n"
                "attribute vec4 a_position;\n"
                "attribute vec2 a_tex;\n"
                "varying vec2 v_tex;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    v_tex = a_tex;\n"
                "    gl_Position = u_wvpMatrix * a_position;\n"
                "}";

/* Fragment Shader texture Source */
static const char fragment_tex_shader[] =
        "#ifdef GL_ES\n"
                "precision mediump float;\n"
                "#endif\n"
                "uniform sampler2D u_texSampler;\n"
                "varying vec2 v_tex;\n"
                "\n"
                "void main (void)\n"
                "{\n"
                "    gl_FragColor = texture2D(u_texSampler, v_tex);\n"
                "}";

static void
create_vbo(appdata_s* ad) {
	glGenBuffers(1, &ad->vbo_vertex);
    glGenBuffers(1, &ad->vbo_color);
    glGenBuffers(1, &ad->vbo_texture);

    glBindBuffer(GL_ARRAY_BUFFER, ad->vbo_vertex);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(ad->idx_a_position, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    glBindBuffer(GL_ARRAY_BUFFER, ad->vbo_color);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_colors), cube_colors, GL_STATIC_DRAW);
    glVertexAttribPointer(ad->idx_a_color, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

    glBindBuffer(GL_ARRAY_BUFFER, ad->vbo_texture);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_texs), cube_texs, GL_STATIC_DRAW);
    glVertexAttribPointer(ad->idx_a_tex, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    glEnableVertexAttribArray(ad->idx_a_position);
    glEnableVertexAttribArray(ad->idx_a_color);
    glEnableVertexAttribArray(ad->idx_a_tex);

    glGenBuffers(1, &ad->vbo_index);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ad->vbo_index);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices, GL_STATIC_DRAW);
}


static void
init_shader_program(appdata_s* ad) {
    const char *p;

    p = vertex_tex_shader;
    ad->vtx_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(ad->vtx_shader, 1, &p, NULL);
    glCompileShader(ad->vtx_shader);

    GLint compiled = 0;
    glGetShaderiv(ad->vtx_shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) exit(1);

    p = fragment_tex_shader;
    ad->fgmt_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(ad->fgmt_shader, 1, &p, NULL);
    glCompileShader(ad->fgmt_shader);

    glGetShaderiv(ad->fgmt_shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) exit(1);


    ad->program = glCreateProgram();
    glAttachShader(ad->program, ad->vtx_shader);
    glAttachShader(ad->program, ad->fgmt_shader);

    glLinkProgram(ad->program);

    GLint linkStatus = GL_FALSE;
    glGetProgramiv(ad->program, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE) exit(1);


    ad->idx_a_position = glGetAttribLocation(ad->program, "a_position");
    ad->idx_a_color = glGetAttribLocation(ad->program, "a_color");
    ad->idx_a_tex = glGetAttribLocation(ad->program, "a_tex");

    ad->idx_wvp = glGetUniformLocation(ad->program, "u_wvpMatrix");
    ad->idx_tex = glGetUniformLocation(ad->program, "u_texSampler");

    glUseProgram(ad->program);
}

static void
mouse_down_cb(void *data, Evas *e, Evas_Object *obj, void *event_info) {
    appdata_s *ad = (appdata_s *) data;
    if (!ad->reset_anim) {
        ad->mouse_down = EINA_TRUE;
        elm_glview_changed_set(obj);
    }
}

static float
clamp_angle(const float target)
{
    if(target > 360.0f)
        return target - 360.0f;
    else if(target < 0.0f)
        return target + 360.0f;
    else
        return target;
}

static void
mouse_move_cb(void *data, Evas *e, Evas_Object *obj, void *event_info) {
    Evas_Event_Mouse_Move *ev;
    ev = (Evas_Event_Mouse_Move *) event_info;
    appdata_s *ad = (appdata_s *) data;
    if (!ad->reset_anim) {

        float dx = 0, dy = 0;

        if (ad->mouse_down) {
            dx = ev->cur.canvas.x - ev->prev.canvas.x;
            dy = ev->cur.canvas.y - ev->prev.canvas.y;
            ad->xangle += dy;
            ad->yangle += dx;
            ad->xangle = clamp_angle(ad->xangle);
            ad->yangle = clamp_angle(ad->yangle);
        }
        elm_glview_changed_set(obj);
    }
}

static void
mouse_up_cb(void *data, Evas *e, Evas_Object *obj, void *event_info) {
    appdata_s *ad = (appdata_s *) data;
    if (!ad->reset_anim) {

        ad->mouse_down = EINA_FALSE;
        elm_glview_changed_set(obj);
    }
}

// GL Init function
static void
init_glview(Evas_Object *glview) {
    // Set gl state color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    appdata_s *ad = (appdata_s *) evas_object_data_get(glview, "ad");

    if (!ad->initialized) {
        init_shader_program(ad);
        create_vbo(ad);
        ad->texture = create_texture(ad->win, "tizen_noalpha.png");

        glEnable(GL_DEPTH_TEST);
        ad->initialized = EINA_TRUE;
    }

    ad->xangle = 45.0f;
    ad->yangle = 45.0f;
}

// GLView resize function
static void
resize_glview(Evas_Object *glview) {
    appdata_s *ad = (appdata_s *) evas_object_data_get(glview, "ad");

    int w, h;
    elm_glview_size_get(glview, &w, &h);
    ad->glview_w = w;
    ad->glview_h = h;
    glViewport(0, 0, w, h);
}

// GL draw callback
static void
draw_glview(Evas_Object *glview) {

    appdata_s *ad = (appdata_s *) evas_object_data_get(glview, "ad");
    float world[16], viewproj[16];
    float aspect;

    if (!ad)
        return;

    init_matrix(world);
    init_matrix(viewproj);

    aspect = (float) ad->glview_w / (float) ad->glview_h;

    // view matrix is the identity matrix
    view_set_perspective(viewproj, 60.0f, aspect, 1.0f, 20.0f);

    translate_xyz(world, 0.0f, 0.0f, -2.5f);
    rotate_xyz(world, ad->xangle, ad->yangle, 0.0f);

    multiply_matrix(ad->wvp, viewproj, world);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUniformMatrix4fv(ad->idx_wvp, 1, GL_FALSE, ad->wvp);

    glBindTexture(GL_TEXTURE_2D, ad->texture);
    glActiveTexture(GL_TEXTURE0);
    glUniform1i(ad->idx_tex, 0);

    glDrawElements(GL_TRIANGLES, cube_indices_count, GL_UNSIGNED_SHORT, 0);

    glFlush();

}

// Delete GLView callback
static void
del_glview(Evas_Object *glview) {
    appdata_s *ad = (appdata_s *) evas_object_data_get(glview, "ad");

    glDeleteShader(ad->vtx_shader);
    glDeleteShader(ad->fgmt_shader);
    glDeleteProgram(ad->program);

    evas_object_data_del((Evas_Object *) glview, "ad");
}

Evas_Object *
add_glview(Evas_Object *parent, appdata_s *ad) {
    Evas_Object *glview;

    /* Create and initialize GLView */
    glview = elm_glview_add(parent);
    evas_object_data_set(glview, "ad", ad);

    ELEMENTARY_GLVIEW_GLOBAL_USE(glview);
    evas_object_size_hint_weight_set(glview, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
    evas_object_size_hint_align_set(glview, EVAS_HINT_FILL, EVAS_HINT_FILL);

    /* Request a surface with alpha and a depth buffer */
    elm_glview_mode_set(glview, ELM_GLVIEW_ALPHA | ELM_GLVIEW_DEPTH);

    /* The resize policy tells GLView what to do with the surface when it
     * resizes. ELM_GLVIEW_RESIZE_POLICY_RECREATE will tell it to
     * destroy the current surface and recreate it to the new size.
     */
    elm_glview_resize_policy_set(glview, ELM_GLVIEW_RESIZE_POLICY_RECREATE);

    /* The render policy sets how GLView should render GL code.
     * ELM_GLVIEW_RENDER_POLICY_ON_DEMAND will have the GL callback
     * called only when the object is visible.
     * ELM_GLVIEW_RENDER_POLICY_ALWAYS would cause the callback to be
     * called even if the object were hidden.
     */
    elm_glview_render_policy_set(glview, ELM_GLVIEW_RENDER_POLICY_ON_DEMAND);

    /* The initialize callback function gets registered here */
    elm_glview_init_func_set(glview, init_glview);

    /* The delete callback function gets registered here */
    elm_glview_del_func_set(glview, del_glview);

    /* The resize callback function gets registered here */
    elm_glview_resize_func_set(glview, resize_glview);

    /* The render callback function gets registered here */
    elm_glview_render_func_set(glview, draw_glview);

    elm_object_focus_set(glview, EINA_TRUE);

    evas_object_event_callback_add(glview, EVAS_CALLBACK_MOUSE_DOWN, mouse_down_cb, ad);
    evas_object_event_callback_add(glview, EVAS_CALLBACK_MOUSE_UP, mouse_up_cb, ad);
    evas_object_event_callback_add(glview, EVAS_CALLBACK_MOUSE_MOVE, mouse_move_cb, ad);

    /* Add the GLView to the parent and show it */
    elm_object_content_set(parent, glview);
    evas_object_show(glview);

    return glview;
}
