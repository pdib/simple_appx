Get-AppxPackage *Test* | Remove-AppxPackage
Write-Host "${$PSScriptRoot}";
Add-AppxPackage "$($PSScriptRoot)\appbundle.appx"