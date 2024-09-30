class Queen{
    //giving queen objs coloumn, positive and negative diagonal attributes
     int coloumn;
     int posDiagonal;
     int negDiagonal;
     
     public:
     
     //itializing constructors
     Queen();
     
     Queen(int coloumn, int negDiagonal, int posDiagonal);
     
     //getter and setters
     int getNegDiagonal();
     
     int getPosDiagonal();
     
     int getColoumn();
     
     void setNegDiagonal(int negDiagonal);
     
     void setColoumn(int coloumn);
     
     void setPosDiagonal(int posDiagonal);
};