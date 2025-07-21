include <BOSL2/std.scad>

module base_shape(height=4) {
    rounded_prism(rect([52, 92], chamfer=[-25, 0, 0, -25]), height=height, joint_sides=5);
}

module spacer(height, outer_radius=2.5, inner_radius=1.1) {
    difference() {
        cylinder(r=outer_radius, h=height, center=true);
        cylinder(r=inner_radius, h=height + 0.1, center=true);
    }
}