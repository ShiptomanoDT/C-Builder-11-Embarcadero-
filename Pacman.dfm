object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 559
  ClientWidth = 827
  Color = 2564384
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnMouseMove = FormMouseMove
  OnPaint = FormPaint
  TextHeight = 15
  object Label1: TLabel
    Left = 40
    Top = 512
    Width = 56
    Height = 15
    Caption = 'X: 0      Y: 0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 144
    Top = 512
    Width = 44
    Height = 15
    Caption = 'control: '
  end
  object Timer1: TTimer
    Interval = 16
    OnTimer = Timer1Timer
    Left = 792
    Top = 8
  end
end
