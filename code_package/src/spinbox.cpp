#include<spinbox.h>
void spinbox_vx::Show_Vx_value(float vx)
{
    setEnabled(true);
    setValue(vx);

}
void spinbox_vx::box_disable()
{
    setEnabled(false);
}

void spinbox_vy::Show_Vy_value(float vy)
{
    setEnabled(true);
    setValue(vy);
}
void spinbox_vy::box_disable()
{
    setEnabled(false);
}

void spinbox_vz::Show_Vz_value(float vz)
{
    setEnabled(true);
    setValue(vz);
}
void spinbox_vz::box_disable()
{
    setEnabled(false);
}

void spinbox_color_R::Show_color_R(float r)
{
    setEnabled(true);
    setValue(r);
}
void spinbox_color_R::box_disable()
{
    setEnabled(false);
}
void spinbox_color_G::Show_color_G(float g)
{
    setEnabled(true);
    setValue(g);
}
void spinbox_color_G::box_disable()
{
    setEnabled(false);
}

void spinbox_color_B::Show_color_B(float b)
{
    setEnabled(true);
    setValue(b);
}
void spinbox_color_B::box_disable()
{
    setEnabled(false);
}
