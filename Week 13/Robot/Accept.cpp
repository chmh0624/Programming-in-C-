int main()
{
    std::string ins, tmp;
    Robot robot;
    while (std::cin >> ins)
    {
        if (ins == "GO")
        {
            int n;
            std::cin >> n;
            while (n--)
                robot.go();
            std::cin >> ins;
        }
        else if (ins == "TURN")
        {
            std::string way;
            std::cin >> way;
            robot.turn(way);
        }
        else if (ins == "TURNTO")
        {
            char dir;
            std::cin >> dir;
            while (dir != robot.getDirection())
                robot.turn("RIGHT");
        }
        else if (ins == "GOTO")
        {
            int x, y;
            std::cin >> x >> y;
            if (x > robot.getPositionX())
            {
                while ('E' != robot.getDirection())
                    robot.turn("RIGHT");
                while (x > robot.getPositionX())
                    robot.go();
            }
            else if (x < robot.getPositionX())
            {
                while ('W' != robot.getDirection())
                    robot.turn("RIGHT");
                while (x > robot.getPositionX())
                    robot.go();
            }
            if (y > robot.getPositionY())
            {
                while ('N' != robot.getDirection())
                    robot.turn("RIGHT");
                while (y > robot.getPositionY())
                    robot.go();
            }
            else if (y < robot.getPositionY())
            {
                while ('S' != robot.getDirection())
                    robot.turn("RIGHT");
                while (y < robot.getPositionY())
                    robot.go();
            }
            while ('N' != robot.getDirection())
                robot.turn("RIGHT");
        }
        else if (ins == "SHOWINFO")
        {
            robot.display();
        }
        else
        {
            break;
        }
    }
}
