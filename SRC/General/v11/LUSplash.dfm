object FormSplash: TFormSplash
  Left = 360
  Top = 333
  ActiveControl = PanelText
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  ClientHeight = 62
  ClientWidth = 465
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object PanelText: TPanel
    Left = 0
    Top = 0
    Width = 465
    Height = 21
    Align = alTop
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object ProgressBar: TProgressBar
    Left = 0
    Top = 41
    Width = 465
    Height = 21
    Align = alBottom
    TabOrder = 1
  end
  object PanelCaption: TPanel
    Left = 0
    Top = 21
    Width = 465
    Height = 20
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
end
