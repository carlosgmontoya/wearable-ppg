import asyncio
from bleak import BleakClient

address = "55:7A:7F:D1:5C:F0"

async def main():
    async with BleakClient(address) as client:
        for service in client.services:
            print(service)

asyncio.run(main())