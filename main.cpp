#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
 int N=30,M=20;
int size=16;
int w = size*N;
int h = size*M;

int dir,num=4;

struct Snake
{ int x,y;}  s[100];

struct Fruit
{ int x,y;} f;

void Tick()
 {
     // shift elements
    for (int i=num;i>0;--i)
     {s[i].x=s[i-1].x; s[i].y=s[i-1].y;}

    if (dir==0)
        s[0].y+=1;
    if (dir==1)
     s[0].x-=1;
    if (dir==2)
     s[0].x+=1;
    if (dir==3)
     s[0].y-=1;
    // generate fruits
    if ((s[0].x==f.x) && (s[0].y==f.y))
     {
         num++;
     f.x=rand()%N;
      f.y=rand()%M;
     }
    // 3shan ybd2 mn L na7ia L tania lma ywsl le nhayet L board
    if (s[0].x>N)
        s[0].x=0;
    if (s[0].x<0)
        s[0].x=N;
    if (s[0].y>M)
      s[0].y=0;
    if (s[0].y<0)
        s[0].y=M;
   // 3shan L t3ban meakol4 nafsoo
    for (int i=1;i<num;i++)
     if (s[0].x==s[i].x && s[0].y==s[i].y)
        num=i;
 }
int main()
{

    srand(time(0));
    RenderWindow window(VideoMode(w, h), " Snake Game ");
    Texture t1,t2,t3;

    t1.loadFromFile("bigwhite.png");
    t2.loadFromFile("green.png");
    t3.loadFromFile("red.png");

    Sprite sprite1;
    Sprite sprite2;
    Sprite sprite3;

    sprite1.setTexture(t1);
    sprite1.setColor(Color(0,255,255));
    sprite2.setTexture(t2);
    sprite3.setTexture(t3);

     Clock clock;
    float timer=0, delay=0.1;
    f.x=10;
    f.y=10;
    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }
         if (Keyboard::isKeyPressed(Keyboard::Up))
         {
             dir=3;
         }

         if (Keyboard::isKeyPressed(Keyboard::Down))
         {
             dir=0;
         }

         if (Keyboard::isKeyPressed(Keyboard::Right))
         {
             dir=2;
         }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            dir=1;
        }

        if (timer>delay)
            {
                timer=0;
               Tick();
        }

   // to draw

    window.clear();
   // draw graph

    for (int i=0; i<N; i++)
    {
      for (int j=0; j<M; j++)
        {
              sprite1.setPosition(i*size, j*size);
              window.draw(sprite1);
        }
    }
      // draw snake

    for (int i=0;i<num;i++)
        {
              sprite2.setPosition(s[i].x*size, s[i].y*size);
              window.draw(sprite2);
        }
     // draw fruit
    sprite3.setPosition(f.x*size, f.y*size);
     window.draw(sprite3);

    window.display();

    }

    return 0;
}
