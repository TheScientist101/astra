use <basics.scad>
use <case_bottom.scad>
use <case_top.scad>

height = 4;

translate([0, 0, 8]) {
    case_top(height=height);

    // spacers
    translate([-21.06, -18.4, -height / 2 - 0.1 - 2.5]) spacer(height=5);
    translate([-21.06, 19.74, -height / 2 - 0.1 - 2.5]) spacer(height=5);
    translate([8.44, -20.39, -height / 2 - 0.1 - 2.5]) spacer(height=5);
}
color("green") rotate([0, 0, 90]) import("./components/pcb.stl");
translate([0, 0, -7]) {
    case_bottom(height=height);

    // spacers
    translate([-21.06, -18.4, height / 2 + 0.1 + 2.5]) spacer(height=5);
    translate([-21.06, 19.74, height / 2 + 0.1 + 2.5]) spacer(height=5);
    translate([8.44, -20.39, height / 2 + 0.1 + 2.5]) spacer(height=5);
}

translate([42, -42.5, 0.5]) spacer(height=10.9);
translate([42, 42.5, 0.5]) spacer(height=10.9);