# Define the registry path and value
$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\StuckRects3"
$regValue = Get-ItemProperty -Path $regPath -Name Settings

# Check the current state of the taskbar auto-hide setting
$currentValue = $regValue.Settings
$autoHideEnabled = $currentValue[8] -band 0x01

if ($autoHideEnabled -eq 0) {
    # Enable auto-hide
    $currentValue[8] = $currentValue[8] -bor 0x01
    Write-Host "Taskbar auto-hide enabled."
} else {
    # Disable auto-hide
    $currentValue[8] = $currentValue[8] -band 0xFE
    Write-Host "Taskbar auto-hide disabled."
}

# Write the updated value back to the registry
Set-ItemProperty -Path $regPath -Name Settings -Value $currentValue

# Restart Explorer to apply changes
Stop-Process -Name explorer -Force
Start-Process explorer
