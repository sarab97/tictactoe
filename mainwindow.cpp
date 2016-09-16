#include "mainwindow.h"
#include "ui_mainwindow.h"

int cnt=1;
int chanc=0;
int cont=1;
char sq[3][3]={'\0'};
int tplayersc=0;
int lplcn=0;
QString tplayers[50];
QString players[3];
int player=1;
int ecnt = 0;
int start=0;
char win = '\0';
QString winners[25];
int wicn=0;
int mode = 2;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tic Tac Toe");
    //this->setWindowIcon();
    ui->radioButton->setVisible(0);
    ui->radioButton_2->setVisible(0);
    ui->radioButton_3->setVisible(0);
    ui->radioButton_4->setVisible(0);
    ui->label_5->setVisible(0);
    ui->lineEdit_3->setVisible(0);
    ui->lineEdit_4->setVisible(0);
    ui->pushButton_4->setVisible(0);
    ui->label_9->setVisible(0);
    ui->pushButton_5->setVisible(0);
    ui->label_10->setVisible(0);
    ui->label_7->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

char checkwin()
{
    win = '\0';
    for(int i=0;i<3;i++)
    {
        if(sq[i][0] == sq[i][1] && sq[i][1]==sq[i][2] && sq[i][1] != '\0')
        {
            win = sq[i][1];
            break;
        }
        if(sq[0][i] == sq[1][i] && sq[1][i]==sq[2][i] && sq[1][i] != '\0')
        {
            win = sq[1][i];
            break;
        }
    }
    if(sq[0][0] == sq[1][1] && sq[1][1]==sq[2][2] && sq[1][1] != '\0')
        win = sq[1][1];
    if(sq[0][2] == sq[1][1] && sq[1][1]==sq[2][0] && sq[1][1] != '\0')
        win = sq[1][1];
    return win;
}
int chmv(char player1, char player2);
int cpmove(char player1, char player2)
{

	int bms = -99;
	int ro = -99;
	int cl = -99;
    int scor = 0;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (sq[r][c] == '\0')
			{
				sq[r][c] = player1;
				scor = -(chmv(player2, player1));
                sq[r][c] = '\0';
				if (scor >= bms)
				{
                    bms = scor;
                    ro = r;
                    cl = c;
                }
            }
        }
    }
    return (10*ro + cl);
}

int chmv(char player1, char player2)
{

	int bms = -99;
    int scor = 0;

    if (checkwin() == player1)
        return 1000;

    else if (checkwin() == player2)
        return -1000;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (sq[r][c] == '\0')
			{
				sq[r][c] = player1;
				scor = -(chmv(player2, player1));
                sq[r][c] = '\0';
				if (scor >= bms)
                    bms = scor;
            }
        }
    }

    if (bms == -9999 || bms == 0)
        return 0;

    else if (bms < 0)
        return bms + 1;

    else if (bms > 0)
        return bms - 1;
}

void MainWindow::chplayer()
{
    win='\0';
    for(int i=0;i<3;i++)
    {
        if(sq[i][0] == sq[i][1] && sq[i][1]==sq[i][2] && sq[i][1] != '\0')
        {
            win = sq[i][1];
            break;
        }
        if(sq[0][i] == sq[1][i] && sq[1][i]==sq[2][i] && sq[1][i] != '\0')
        {
            win = sq[1][i];
            break;
        }
    }
    if(sq[0][0] == sq[1][1] && sq[1][1]==sq[2][2] && sq[1][1] != '\0')
        win = sq[1][1];
    if(sq[0][2] == sq[1][1] && sq[1][1]==sq[2][0] && sq[1][1] != '\0')
        win = sq[1][1];

    if(win=='X')
    {
        start=0;
        ui->label_4->setText(players[1]+" Wins");
        winners[cont++]=players[1];
        if(lplcn > 0)
        {
            ui->label_9->setVisible(1);
            players[1] = tplayers[cnt++];
            players[2] = tplayers[cnt++];
            ui->label_9->setText(players[1]+" Vs "+players[2]);
            ui->pushButton_5->setVisible(1);
            lplcn-=2;
        }
        else
        {
            if(mode == 3)
            {
                //ui->pushButton_5->setVisible(1);
                //ui->pushButton_5->setText("Winners");
                ui->label_10->setVisible(1);
                for(int i=1;i<cont;i++)
                    ui->label_10->setText(ui->label_10->text()+"\n"+i+". "+winners[i]);
            }
        }
        return;
    }
    if(win=='O')
    {
        start=0;
        ui->label_4->setText(players[2]+" Wins");
        winners[cont++]=players[2];
        if(lplcn > 0)
        {
            ui->label_9->setVisible(1);
            players[1] = tplayers[cnt++];
            players[2] = tplayers[cnt++];
            ui->label_9->setText(players[1]+" Vs "+players[2]);
            ui->pushButton_5->setVisible(1);
            lplcn-=2;
        }
        else
        {
            if(mode == 3)
            {
                //ui->pushButton_5->setVisible(1);
                //ui->pushButton_5->setText("Winners");
                ui->label_10->setVisible(1);
                for(int i=1;i<cont;i++)
                    ui->label_10->setText(ui->label_10->text()+"\n"+i+". "+winners[i]);
            }
        }
        return;
    }
    chanc++;
    if(chanc == 9)
    {
        ui->label_4->setText("Game draw");
        chanc=0;
        start=0;
        winners[cont++]="Game Draw";
        if(lplcn > 0)
        {
            ui->label_9->setVisible(1);
            players[1] = tplayers[cnt++];
            players[2] = tplayers[cnt++];
            ui->label_9->setText(players[1]+" Vs "+players[2]);
            ui->pushButton_5->setVisible(1);
            lplcn-=2;
        }
        else
        {
            if(mode == 3)
            {
                //ui->pushButton_5->setVisible(1);
                //ui->pushButton_5->setText("Winners");
                ui->label_10->setVisible(1);
                for(int i=1;i<cont;i++)
                    ui->label_10->setText(ui->label_10->text()+"\n"+i+". "+winners[i]);
            }
        }
        return;
    }

    if(player==1)
        player=2;
    else
        player=1;
    ui->label_4->setText(players[player]+"'s Turn");
    if(mode == 1 && player == 2)
    {
        int mv = cpmove('O' , 'X');
        int ro = mv / 10;
        int cl = mv % 10;
        sq[ro][cl] = 'O';
        switch(mv)
        {
            case 00:
                ui->toolButton->setText("O");
                break;
            case 01:
                ui->toolButton_2->setText("O");
                break;
            case 02:
                ui->toolButton_3->setText("O");
                break;
            case 10:
                ui->toolButton_4->setText("O");
                break;
            case 11:
                ui->toolButton_5->setText("O");
                break;
            case 12:
                ui->toolButton_6->setText("O");
                break;
            case 20:
                ui->toolButton_7->setText("O");
                break;
            case 21:
                ui->toolButton_8->setText("O");
                break;
            case 22:
                ui->toolButton_9->setText("O");
                break;
        }
        chplayer();
    }
}

void MainWindow::on_toolButton_clicked()
{
    if(ui->toolButton->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->toolButton->setText("X");
            sq[0][0] = 'X';
            chplayer();
        }
        else
        {
            ui->toolButton->setText("O");
            sq[0][0] = 'O';
            chplayer();
        }
    }
}

void MainWindow::on_toolButton_2_clicked()
{
    if(ui->toolButton_2->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->toolButton_2->setText("X");
            sq[0][1] = 'X';
            chplayer();
        }
        else
        {
            ui->toolButton_2->setText("O");
            sq[0][1] = 'O';
            chplayer();
        }
    }
}

void MainWindow::on_toolButton_3_clicked()
{
    if(ui->toolButton_3->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->toolButton_3->setText("X");
            sq[0][2] = 'X';
            chplayer();
        }
        else
        {
            ui->toolButton_3->setText("O");
            sq[0][2] = 'O';
            chplayer();
        }
    }
}

void MainWindow::on_toolButton_4_clicked()
{
    if(ui->toolButton_4->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->toolButton_4->setText("X");
            sq[1][0] = 'X';
            chplayer();
        }
        else
        {
            ui->toolButton_4->setText("O");
            sq[1][0] = 'O';
            chplayer();
        }
    }
}

void MainWindow::on_toolButton_5_clicked()
{
    if(ui->toolButton_5->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->toolButton_5->setText("X");
            sq[1][1] = 'X';
            chplayer();
        }
        else
        {
            ui->toolButton_5->setText("O");
            sq[1][1] = 'O';
            chplayer();
        }
    }
}

void MainWindow::on_toolButton_6_clicked()
{
    if(ui->toolButton_6->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->toolButton_6->setText("X");
            sq[1][2] = 'X';
            chplayer();
        }
        else
        {
            ui->toolButton_6->setText("O");
            sq[1][2] = 'O';
            chplayer();
        }
    }
}

void MainWindow::on_toolButton_7_clicked()
{
    if(ui->toolButton_7->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->toolButton_7->setText("X");
            sq[2][0] = 'X';
            chplayer();
        }
        else
        {
            ui->toolButton_7->setText("O");
            sq[2][0] = 'O';
            chplayer();
        }
    }
}

void MainWindow::on_toolButton_8_clicked()
{
    if(ui->toolButton_8->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->toolButton_8->setText("X");
            sq[2][1] = 'X';
            chplayer();
        }
        else
        {
            ui->toolButton_8->setText("O");
            sq[2][1] = 'O';
            chplayer();
        }
    }
}

void MainWindow::on_toolButton_9_clicked()
{
    if(ui->toolButton_9->text() == "" && start == 1)
    {
        if(player==1)
        {
            ui->toolButton_9->setText("X");
            sq[2][2] = 'X';
            chplayer();
        }
        else
        {
            ui->toolButton_9->setText("O");
            sq[2][2] = 'O';
            chplayer();
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    player=1;
    ecnt = 0;
    win = '\0';
    wicn=0;
    chanc=0;
    if(mode == 2)
    players[1]=ui->lineEdit->text();
    players[2]=ui->lineEdit_2->text();
    if(mode == 1)
    {
        players[2] = "CPU";
    }

    if(mode == 3)
    {
        players[1] = tplayers[cnt++];
        players[2] = tplayers[cnt++];
        lplcn=lplcn-2;
    }
        ui->radioButton->setVisible(0);
        ui->radioButton_2->setVisible(0);
        ui->radioButton_3->setVisible(0);
        ui->radioButton_4->setVisible(0);
        ui->label_5->setVisible(0);
        ui->label_7->setVisible(0);
        ui->lineEdit_3->setVisible(0);
        ui->lineEdit_4->setVisible(0);
        ui->pushButton_4->setVisible(0);
    ui->label_8->setText(players[1]+" Vs "+players[2]);
    if(players[1] == "" || players[2] == "")
    {
        ui->label_4->setText("Enter Names of players");
    }
    else
    {
        ui->label_4->setText(players[1]+"'s Turn");
        start=1;
    }
    win='\0';
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            sq[i][j]={'\0'};
    ui->toolButton->setText("");
    ui->toolButton_2->setText("");
    ui->toolButton_3->setText("");
    ui->toolButton_4->setText("");
    ui->toolButton_5->setText("");
    ui->toolButton_6->setText("");
    ui->toolButton_7->setText("");
    ui->toolButton_8->setText("");
    ui->toolButton_9->setText("");
}

void MainWindow::on_pushButton_2_clicked()
{
    win='\0';
    cnt=1;
    cont=1;
    tplayersc=0;
    lplcn=0;
    player=1;
    ecnt = 0;
    win = '\0';
    wicn=0;
    //mode = 2;
    chanc=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            sq[i][j]={'\0'};
    ui->toolButton->setText("");
    ui->toolButton_2->setText("");
    ui->toolButton_3->setText("");
    ui->toolButton_4->setText("");
    ui->toolButton_5->setText("");
    ui->toolButton_6->setText("");
    ui->toolButton_7->setText("");
    ui->toolButton_8->setText("");
    ui->toolButton_9->setText("");
    player=1;
    start=1;
    ui->label_4->setText(players[1]+"'s Turn");
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->radioButton->isVisible() == true)
    {
        ui->radioButton->setVisible(0);
        ui->radioButton_2->setVisible(0);
        ui->radioButton_3->setVisible(0);
        ui->radioButton_4->setVisible(0);
    }
    else
    {
        ui->radioButton->setVisible(1);
        ui->radioButton_2->setVisible(1);
        ui->radioButton_3->setVisible(1);
        ui->radioButton_4->setVisible(1);
    }
}

void MainWindow::on_lineEdit_3_returnPressed()
{
    if(ui->lineEdit_3->text() == "")
        return;

    if(mode == 1)
    {
        players[1] = ui->lineEdit_3->text();
        players[2] = "CPU";
        ui->label_4->setText("Start the game");
        return;
    }

    if(mode == 3)
    {
        if(ecnt == 1)
        {
            tplayersc = ui->lineEdit_3->text().toInt();
            lplcn = tplayersc;
            ecnt=0;
            ui->label_5->setText("Enter Player 1 Name");
            ui->lineEdit_3->setText("");
        }
        else
        {
            tplayers[cnt]=ui->lineEdit_3->text();
            ui->label_7->setText(tplayers[cnt]);
            cnt++;
            if(cnt<=tplayersc)
            ui->label_5->setText("Enter Player "+ QString::number(cnt) +" Name");
            ui->lineEdit_3->setText("");
        }

        if(cnt > tplayersc && tplayersc != 0)
        {
            ui->label_4->setText("Start the game");
            cnt=1;
            return;
        }
    }
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->label_5->setVisible(1);
    ui->lineEdit_3->setVisible(1);
    mode = 3;
    ecnt = 1;
    ui->label_6->setText("Multiplayer");
    ui->pushButton_4->setVisible(1);
}

void MainWindow::on_radioButton_clicked()
{
    mode = 1;
    ui->label_6->setText("Single Player");
    ui->label_5->setVisible(1);
    ui->lineEdit_3->setVisible(1);
    ui->label_5->setText("Enter your name");
    ui->pushButton_4->setVisible(1);
}

void MainWindow::on_radioButton_2_clicked()
{
    mode = 2;
    ui->label_6->setText("2 Player Game");
    ui->label_5->setVisible(0);
    ui->lineEdit_3->setVisible(0);
    ui->pushButton_4->setVisible(0);
}

void MainWindow::on_radioButton_4_clicked()
{
    mode = 4;
    ui->label_6->setText("Team Match");
    ui->label_5->setVisible(0);
    ui->lineEdit_3->setVisible(0);
    ui->pushButton_4->setVisible(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->lineEdit_3->text() == "")
        return;

    if(mode == 1)
    {
        players[1] = ui->lineEdit_3->text();
        players[2] = "CPU";
        ui->label_4->setText("Start the game");
        return;
    }

    if(mode == 3)
    {
        if(ecnt == 1)
        {
            tplayersc = ui->lineEdit_3->text().toInt();
            lplcn = tplayersc;
            ecnt=0;
            ui->label_5->setText("Enter Player 1 Name");
            ui->lineEdit_3->setText("");
        }
        else
        {
            tplayers[cnt]=ui->lineEdit_3->text();
            ui->label_7->setText(tplayers[cnt]);
            cnt++;
            if(cnt<=tplayersc)
            ui->label_5->setText("Enter Player "+ QString::number(cnt) +" Name");
            ui->lineEdit_3->setText("");
        }

        if(cnt > tplayersc && tplayersc != 0)
        {
            ui->label_4->setText("Start the game");
            cnt=1;
            return;
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->label_8->setText(ui->label_9->text());
    ui->label_9->setVisible(0);
    ui->pushButton_5->setVisible(0);
    win='\0';
    chanc=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            sq[i][j]={'\0'};
    ui->toolButton->setText("");
    ui->toolButton_2->setText("");
    ui->toolButton_3->setText("");
    ui->toolButton_4->setText("");
    ui->toolButton_5->setText("");
    ui->toolButton_6->setText("");
    ui->toolButton_7->setText("");
    ui->toolButton_8->setText("");
    ui->toolButton_9->setText("");
    player=1;
    start=1;
    ui->label_4->setText(players[1]+"'s Turn");
}
