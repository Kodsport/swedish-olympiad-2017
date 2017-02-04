unitsize(1cm);

void drawbox(real x, real y, bool all) {
    if (all) {
        fill(box((0+x,0+y), (3+x,3+y)), blue);
        draw(box((0+x,0+y), (3+x,3+y)));
    }
    fill(box((0.5+x,0.5+y), (2.5+x,2.5+y)), red);
    draw(box((0.5+x,0.5+y), (2.5+x,2.5+y)));
    fill(box((1+x,1+y), (2+x,2+y)), green);
    draw(box((1+x,1+y), (2+x,2+y)));
}

drawbox(0,0,true);
drawbox(4,0,false);
