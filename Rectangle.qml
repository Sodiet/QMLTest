import QtQuick 2.7
import QtQuick.Controls 1.4

Item{
    signal testSignal(real x, real y);

    Rectangle{
        id: rct;
        x: 0;
        y: 0;
        color: "green";
        border.color: "black";
        width: 100;
        height: 100;

        Connections{
            target: widget;

            onSetX: {
                rct.x = value;
            }
            onSetY:{
                rct.y = value;
            }
            onSetWidth:{
                rct.width = value;
            }
            onSetHeight:{
                rct.height = value;
            }
        }

        MouseArea{
            id: mouseAreaTest;
            anchors.fill: parent;
            hoverEnabled: true;

            onPressed: {
                rct.color = "red";
                txtField.text = "Ай!";
                testSignal(mouseX, mouseY)
            }
            onReleased:{
                rct.color = "green";
                txtField.text = "Хм...";
            }
        }
    }

    TextField{
        id: txtField
        x: 0
        y: 200
        readOnly: true
    }
}

