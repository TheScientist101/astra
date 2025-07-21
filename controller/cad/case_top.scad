include <BOSL2/std.scad>
use <basics.scad>

module case_top(height=4) {
    difference() {
        base_shape(height=height);
        translate([-8.5, -30.5, 0]) cylinder(r=10.5, h=height + 1, center=true);
        translate([-8.5, 29.5, 0]) cylinder(r=10.5, h=height + 1, center=true);
        for (i = [0:1]) {
            for (j = [0:1]) {
                translate([i * 14.76 - 10.72, j * 16.37 - 16.37/2, 0]) cylinder(r=13.4/2, h=height + 1, center=true);
            }
        }

        translate([17, -18, 0]) cylinder(r=2.5, h=height + 1, center=true);
        translate([17, 11.4, 0]) cylinder(r=2.5, h=height + 1, center=true);
        translate([14, 23.4, 0]) cylinder(r=2.5, h=height + 1, center=true);

        translate([-21.06, -18.4, 0]) cylinder(r=1.1, h=height + 1, center=true);
        translate([-21.06, 19.74, 0]) cylinder(r=1.1, h=height + 1, center=true);
        translate([8.44, -20.39, 0]) cylinder(r=1.1, h=height + 1, center=true);

        translate([42, -42.5, 0]) cylinder(r=1.1, h=height + 1, center=true);
        translate([42, 42.5, 0]) cylinder(r=1.1, h=height + 1, center=true);
    }
}

translate([0, 0, 8]) case_top();
color("green") rotate([0, 0, 90]) import("./components/pcb.stl");