object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 502
  ClientWidth = 773
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 0
    Width = 120
    Height = 25
    Caption = 'Crear lista'
    TabOrder = 0
    StyleElements = [seFont, seBorder]
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 31
    Width = 120
    Height = 25
    Caption = 'Inserta primero'
    TabOrder = 1
    StyleElements = [seFont, seBorder]
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 62
    Width = 120
    Height = 25
    Caption = 'Inserta final'
    TabOrder = 2
    StyleElements = [seFont, seBorder]
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 93
    Width = 120
    Height = 25
    Caption = 'Mostrar lista'
    TabOrder = 3
    StyleElements = [seFont, seBorder]
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 124
    Width = 120
    Height = 25
    Caption = 'Crear polinomio'
    TabOrder = 4
    StyleElements = [seFont, seBorder]
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 155
    Width = 120
    Height = 25
    Caption = 'Insertar termino'
    TabOrder = 5
    StyleElements = [seFont, seBorder]
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 186
    Width = 120
    Height = 25
    Caption = 'Derivar'
    TabOrder = 6
    StyleElements = [seFont, seBorder]
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 8
    Top = 217
    Width = 120
    Height = 25
    Caption = 'Suprimir'
    TabOrder = 7
    StyleElements = [seFont, seBorder]
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 8
    Top = 279
    Width = 120
    Height = 25
    Caption = 'Crear conjunto A'
    TabOrder = 8
    StyleElements = [seFont, seBorder]
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 8
    Top = 310
    Width = 120
    Height = 25
    Caption = 'Crear conjunto B'
    TabOrder = 9
    StyleElements = [seFont, seBorder]
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 8
    Top = 341
    Width = 120
    Height = 25
    Caption = 'Crear conjunto C'
    TabOrder = 10
    StyleElements = [seFont, seBorder]
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 8
    Top = 372
    Width = 120
    Height = 25
    Caption = 'Insertar'
    TabOrder = 11
    StyleElements = [seFont, seBorder]
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 8
    Top = 403
    Width = 120
    Height = 25
    Caption = 'Union'
    TabOrder = 12
    StyleElements = [seFont, seBorder]
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 8
    Top = 434
    Width = 120
    Height = 25
    Caption = 'Interseccion'
    TabOrder = 13
    StyleElements = [seFont, seBorder]
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 8
    Top = 465
    Width = 120
    Height = 25
    Caption = 'Mostrar'
    TabOrder = 14
    StyleElements = [seFont, seBorder]
    OnClick = Button15Click
  end
  object Edit1: TEdit
    Left = 144
    Top = 32
    Width = 75
    Height = 23
    TabOrder = 15
  end
  object Edit2: TEdit
    Left = 144
    Top = 63
    Width = 75
    Height = 23
    TabOrder = 16
  end
  object Edit3: TEdit
    Left = 144
    Top = 156
    Width = 75
    Height = 23
    TabOrder = 17
  end
  object Edit4: TEdit
    Left = 225
    Top = 156
    Width = 75
    Height = 23
    TabOrder = 18
  end
  object Edit5: TEdit
    Left = 144
    Top = 219
    Width = 75
    Height = 23
    TabOrder = 19
  end
  object Button16: TButton
    Left = 8
    Top = 248
    Width = 120
    Height = 25
    Caption = 'Mostrar'
    TabOrder = 20
    StyleElements = [seFont, seBorder]
    OnClick = Button16Click
  end
  object Button17: TButton
    Left = 376
    Top = 0
    Width = 120
    Height = 25
    Caption = 'Crear matriz'
    TabOrder = 21
    StyleElements = [seFont, seBorder]
    OnClick = Button17Click
  end
  object Button18: TButton
    Left = 376
    Top = 31
    Width = 120
    Height = 25
    Caption = 'Dimencionar matriz'
    TabOrder = 22
    StyleElements = [seFont, seBorder]
    OnClick = Button18Click
  end
  object Button19: TButton
    Left = 376
    Top = 62
    Width = 120
    Height = 25
    Caption = 'Asignar valor'
    TabOrder = 23
    StyleElements = [seFont, seBorder]
    OnClick = Button19Click
  end
  object Button20: TButton
    Left = 376
    Top = 93
    Width = 120
    Height = 25
    Caption = 'Poner dato'
    TabOrder = 24
    StyleElements = [seFont, seBorder]
    OnClick = Button20Click
  end
  object Button21: TButton
    Left = 376
    Top = 124
    Width = 120
    Height = 25
    Caption = 'Mostrar matriz'
    TabOrder = 25
    StyleElements = [seFont, seBorder]
    OnClick = Button21Click
  end
  object Edit6: TEdit
    Left = 512
    Top = 32
    Width = 75
    Height = 23
    TabOrder = 26
  end
  object Edit7: TEdit
    Left = 593
    Top = 32
    Width = 75
    Height = 23
    TabOrder = 27
  end
  object Edit8: TEdit
    Left = 512
    Top = 61
    Width = 75
    Height = 23
    TabOrder = 28
  end
  object Edit9: TEdit
    Left = 512
    Top = 90
    Width = 75
    Height = 23
    TabOrder = 29
    Text = 'f'
  end
  object Edit10: TEdit
    Left = 593
    Top = 90
    Width = 75
    Height = 23
    TabOrder = 30
    Text = 'c'
  end
  object Edit11: TEdit
    Left = 674
    Top = 90
    Width = 75
    Height = 23
    TabOrder = 31
    Text = 'd'
  end
  object Button22: TButton
    Left = 376
    Top = 155
    Width = 120
    Height = 25
    Caption = 'Salir'
    TabOrder = 32
    StyleElements = [seFont, seBorder]
    OnClick = Button22Click
  end
end
