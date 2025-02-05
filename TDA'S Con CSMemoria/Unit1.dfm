object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 666
  ClientWidth = 1146
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 24
    Top = 8
    Width = 120
    Height = 25
    Caption = 'Crear memoria'
    TabOrder = 0
    StyleElements = [seFont, seBorder]
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 24
    Top = 39
    Width = 120
    Height = 25
    Caption = 'Pedir espacio'
    TabOrder = 1
    StyleElements = [seFont, seBorder]
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 24
    Top = 70
    Width = 120
    Height = 25
    Caption = 'Eliminar espacio'
    TabOrder = 2
    StyleElements = [seFont, seBorder]
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 24
    Top = 101
    Width = 120
    Height = 25
    Caption = 'Poner dato'
    TabOrder = 3
    StyleElements = [seFont, seBorder]
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 24
    Top = 132
    Width = 120
    Height = 25
    Caption = 'Mostrar'
    TabOrder = 4
    StyleElements = [seFont, seBorder]
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 24
    Top = 163
    Width = 120
    Height = 25
    Caption = 'Crear lista'
    TabOrder = 5
    StyleElements = [seFont, seBorder]
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 24
    Top = 194
    Width = 120
    Height = 25
    Caption = 'Inserta inicio'
    TabOrder = 6
    StyleElements = [seFont, seBorder]
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 24
    Top = 225
    Width = 120
    Height = 25
    Caption = 'Inserta fin'
    TabOrder = 7
    StyleElements = [seFont, seBorder]
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 24
    Top = 256
    Width = 120
    Height = 25
    Caption = 'Mostrar'
    TabOrder = 8
    StyleElements = [seFont, seBorder]
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 24
    Top = 287
    Width = 120
    Height = 25
    Caption = 'Crear Polinomio'
    TabOrder = 9
    StyleElements = [seFont, seBorder]
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 24
    Top = 318
    Width = 120
    Height = 25
    Caption = 'Poner termino'
    TabOrder = 10
    StyleElements = [seFont, seBorder]
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 24
    Top = 349
    Width = 120
    Height = 25
    Caption = 'Derivar'
    TabOrder = 11
    StyleElements = [seFont, seBorder]
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 24
    Top = 380
    Width = 120
    Height = 25
    Caption = 'Mostrar'
    TabOrder = 12
    StyleElements = [seFont, seBorder]
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 24
    Top = 411
    Width = 120
    Height = 25
    Caption = 'Crear conjunto A'
    TabOrder = 13
    StyleElements = [seFont, seBorder]
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 24
    Top = 442
    Width = 120
    Height = 25
    Caption = 'Crear conjunto B'
    TabOrder = 14
    StyleElements = [seFont, seBorder]
    OnClick = Button15Click
  end
  object Button16: TButton
    Left = 24
    Top = 473
    Width = 120
    Height = 25
    Caption = 'Crear conjunto C'
    TabOrder = 15
    StyleElements = [seFont, seBorder]
    OnClick = Button16Click
  end
  object Button17: TButton
    Left = 24
    Top = 504
    Width = 120
    Height = 25
    Caption = 'Inserta elemento'
    TabOrder = 16
    StyleElements = [seFont, seBorder]
    OnClick = Button17Click
  end
  object Button18: TButton
    Left = 24
    Top = 535
    Width = 120
    Height = 25
    Caption = 'Mostrar conjunto'
    TabOrder = 17
    StyleElements = [seFont, seBorder]
    OnClick = Button18Click
  end
  object Button19: TButton
    Left = 24
    Top = 566
    Width = 120
    Height = 25
    Caption = 'Unir '
    TabOrder = 18
    StyleElements = [seFont, seBorder]
    OnClick = Button19Click
  end
  object Button20: TButton
    Left = 24
    Top = 597
    Width = 120
    Height = 25
    Caption = 'Intersectar'
    TabOrder = 19
    StyleElements = [seFont, seBorder]
    OnClick = Button20Click
  end
  object Button21: TButton
    Left = 24
    Top = 628
    Width = 120
    Height = 25
    Caption = 'Salir'
    TabOrder = 20
    StyleElements = [seFont, seBorder]
    OnClick = Button21Click
  end
  object Edit1: TEdit
    Left = 168
    Top = 40
    Width = 121
    Height = 23
    TabOrder = 21
    TextHint = 'x,y,z'
  end
  object Edit2: TEdit
    Left = 168
    Top = 69
    Width = 65
    Height = 23
    TabOrder = 22
    TextHint = 'direcci'#243'n'
  end
  object Edit3: TEdit
    Left = 168
    Top = 102
    Width = 65
    Height = 23
    TabOrder = 23
    TextHint = 'Direcci'#243'n'
  end
  object Edit4: TEdit
    Left = 247
    Top = 102
    Width = 90
    Height = 23
    TabOrder = 24
    Text = '->'
    TextHint = '->x'
  end
  object Edit5: TEdit
    Left = 359
    Top = 102
    Width = 82
    Height = 23
    TabOrder = 25
    TextHint = 'Dato'
  end
  object Edit6: TEdit
    Left = 168
    Top = 133
    Width = 65
    Height = 23
    TabOrder = 26
    Text = '0'
    TextHint = 'Desde'
  end
  object Edit7: TEdit
    Left = 247
    Top = 133
    Width = 65
    Height = 23
    TabOrder = 27
    Text = '10'
    TextHint = 'Hasta'
  end
  object Edit8: TEdit
    Left = 168
    Top = 195
    Width = 65
    Height = 23
    TabOrder = 28
    TextHint = 'Dato'
  end
  object Edit9: TEdit
    Left = 168
    Top = 227
    Width = 65
    Height = 23
    TabOrder = 29
    TextHint = 'Dato'
  end
  object Edit10: TEdit
    Left = 168
    Top = 319
    Width = 66
    Height = 23
    TabOrder = 30
    TextHint = 'Coeficiente'
  end
  object Edit11: TEdit
    Left = 247
    Top = 319
    Width = 65
    Height = 23
    TabOrder = 31
    TextHint = 'Exponente'
  end
  object Button22: TButton
    Left = 327
    Top = 318
    Width = 75
    Height = 25
    Caption = 'Suprime'
    TabOrder = 32
    StyleElements = [seFont, seBorder]
    OnClick = Button22Click
  end
  object Edit12: TEdit
    Left = 424
    Top = 319
    Width = 65
    Height = 23
    TabOrder = 33
    TextHint = 'Exponente'
    StyleElements = [seFont, seBorder]
  end
  object Button23: TButton
    Left = 327
    Top = 380
    Width = 82
    Height = 25
    Caption = 'mostrar Pol_C'
    TabOrder = 34
    StyleElements = [seFont, seBorder]
    OnClick = Button23Click
  end
  object Button24: TButton
    Left = 760
    Top = 8
    Width = 120
    Height = 25
    Caption = 'Crear Matriz'
    TabOrder = 35
    StyleElements = [seFont, seBorder]
    OnClick = Button24Click
  end
  object Button25: TButton
    Left = 760
    Top = 68
    Width = 120
    Height = 25
    Caption = 'Valor repetido'
    TabOrder = 36
    StyleElements = [seFont, seBorder]
    OnClick = Button25Click
  end
  object Button26: TButton
    Left = 760
    Top = 99
    Width = 120
    Height = 25
    Caption = 'Poner'
    TabOrder = 37
    StyleElements = [seFont, seBorder]
    OnClick = Button26Click
  end
  object Button27: TButton
    Left = 760
    Top = 130
    Width = 120
    Height = 25
    Caption = 'Mostrar'
    TabOrder = 38
    StyleElements = [seFont, seBorder]
    OnClick = Button27Click
  end
  object Edit13: TEdit
    Left = 886
    Top = 41
    Width = 75
    Height = 23
    TabOrder = 39
    Text = '5'
    TextHint = 'Filas'
  end
  object Edit14: TEdit
    Left = 967
    Top = 40
    Width = 75
    Height = 23
    TabOrder = 40
    Text = '5'
    TextHint = 'Columnas'
  end
  object Edit15: TEdit
    Left = 886
    Top = 70
    Width = 75
    Height = 23
    TabOrder = 41
    Text = '0'
  end
  object Edit16: TEdit
    Left = 886
    Top = 101
    Width = 75
    Height = 23
    TabOrder = 42
    TextHint = 'Fila'
  end
  object Button28: TButton
    Left = 760
    Top = 37
    Width = 120
    Height = 25
    Caption = 'Dimencionar'
    TabOrder = 45
    StyleElements = [seFont, seBorder]
    OnClick = Button28Click
  end
  object Edit17: TEdit
    Left = 967
    Top = 101
    Width = 75
    Height = 23
    TabOrder = 43
    TextHint = 'Columna'
  end
  object Edit18: TEdit
    Left = 1048
    Top = 100
    Width = 75
    Height = 23
    TabOrder = 44
    TextHint = 'Dato'
  end
  object Button29: TButton
    Left = 760
    Top = 318
    Width = 120
    Height = 25
    Caption = 'Crear pila'
    TabOrder = 46
    StyleElements = [seFont, seBorder]
    OnClick = Button29Click
  end
  object Button30: TButton
    Left = 760
    Top = 349
    Width = 120
    Height = 25
    Caption = 'Apilar'
    TabOrder = 47
    StyleElements = [seFont, seBorder]
    OnClick = Button30Click
  end
  object Button31: TButton
    Left = 760
    Top = 380
    Width = 120
    Height = 25
    Caption = 'Desapilar'
    TabOrder = 48
    StyleElements = [seFont, seBorder]
    OnClick = Button31Click
  end
  object Button32: TButton
    Left = 760
    Top = 411
    Width = 120
    Height = 25
    Caption = 'Infija a posfija'
    TabOrder = 49
    StyleElements = [seFont, seBorder]
    OnClick = Button32Click
  end
  object Button33: TButton
    Left = 760
    Top = 442
    Width = 120
    Height = 25
    Caption = 'Evaluar posfija'
    TabOrder = 50
    StyleElements = [seFont, seBorder]
    OnClick = Button33Click
  end
  object Button34: TButton
    Left = 760
    Top = 473
    Width = 120
    Height = 25
    Caption = 'Mostrar'
    TabOrder = 51
    StyleElements = [seFont, seBorder]
    OnClick = Button34Click
  end
  object Edit19: TEdit
    Left = 896
    Top = 350
    Width = 65
    Height = 23
    TabOrder = 52
    TextHint = 'Dato'
  end
  object Edit20: TEdit
    Left = 896
    Top = 379
    Width = 65
    Height = 23
    TabOrder = 53
  end
  object Edit21: TEdit
    Left = 896
    Top = 408
    Width = 121
    Height = 23
    TabOrder = 54
    TextHint = '5+7*5'
  end
  object Edit22: TEdit
    Left = 896
    Top = 443
    Width = 121
    Height = 23
    TabOrder = 55
    TextHint = '5 7 5 * +'
  end
  object Button35: TButton
    Left = 760
    Top = 504
    Width = 120
    Height = 25
    Caption = 'Crear cola'
    TabOrder = 56
    StyleElements = [seFont, seBorder]
    OnClick = Button35Click
  end
  object Button36: TButton
    Left = 760
    Top = 535
    Width = 120
    Height = 25
    Caption = 'Poner'
    TabOrder = 57
    StyleElements = [seFont, seBorder]
    OnClick = Button36Click
  end
  object Button37: TButton
    Left = 760
    Top = 566
    Width = 120
    Height = 25
    Caption = 'Sacar'
    TabOrder = 58
    StyleElements = [seFont, seBorder]
    OnClick = Button37Click
  end
  object Button38: TButton
    Left = 760
    Top = 597
    Width = 120
    Height = 25
    Caption = 'Mostrar'
    TabOrder = 59
    StyleElements = [seFont, seBorder]
    OnClick = Button38Click
  end
  object Edit23: TEdit
    Left = 896
    Top = 536
    Width = 121
    Height = 23
    TabOrder = 60
    TextHint = 'Dato'
  end
  object Edit24: TEdit
    Left = 896
    Top = 565
    Width = 121
    Height = 23
    TabOrder = 61
  end
end
