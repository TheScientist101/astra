include <BOSL2/std.scad>
use <basics.scad>

module case_bottom(height=4) {
    difference() {
        base_shape(height=height);
        translate([13.76, 28.18, 0]) cuboid([18.6, 24.6, height + 1], rounding=2, except=[TOP, BOTTOM]);
        translate([10, -35, 0]) cuboid([27, 18, height + 1], rounding=2, except=[TOP, BOTTOM]);
        
        translate([-21.06, -18.4, 0]) cylinder(r=1.1, h=height + 1, center=true);
        translate([-21.06, 19.74, 0]) cylinder(r=1.1, h=height + 1, center=true);
        translate([8.44, -20.39, 0]) cylinder(r=1.1, h=height + 1, center=true);
        translate([-21.06, -18.4, -2.5/2]) cylinder(r=3, h=2.5, center=true);
        translate([-21.06, 19.74, -2.5/2]) cylinder(r=3, h=2.5, center=true);
        translate([8.44, -20.39, -2.5/2]) cylinder(r=3, h=2.5, center=true);

        translate([42, -42.5, 0]) cylinder(r=1.1, h=height + 1, center=true);
        translate([42, 42.5, 0]) cylinder(r=1.1, h=height + 1, center=true);
        translate([42, -42.5, -2.5/2]) cylinder(r=3, h=2.5, center=true);
        translate([42, 42.5, -2.5/2]) cylinder(r=3, h=2.5, center=true);
    }
}

translate([0, 0, -7]) case_bottom();
color("green") rotate([0, 0, 90]) import("./components/pcb.stl");