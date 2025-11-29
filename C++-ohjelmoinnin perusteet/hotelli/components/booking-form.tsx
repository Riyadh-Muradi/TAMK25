"use client";

import { useState } from "react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";

export function VarausLomake() {
  const [naytaVahvistus, setNaytaVahvistus] = useState(false);
  const [nimi, setNimi] = useState("");
  const [huoneNumero, setHuoneNumero] = useState("1");
  const [yot, setYot] = useState("1");

  function teeVaraus(e: React.FormEvent) {
    e.preventDefault();
    /* Tarkistetaan syötteet ja tehdään varaus */
    setNaytaVahvistus(true);
  }

  if (naytaVahvistus) {
    /* Lasketaan hinta */
    const hintaYolta = 100;
    const loppuhinta = hintaYolta * parseInt(yot);

    return (
      <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
        <div className="border-border/50 border-b p-4 pb-2">
          <h2 className="text-accent text-sm font-medium">
            Varaus vahvistettu!
          </h2>
        </div>
        <div className="space-y-4 p-4 pt-2">
          <div className="grid grid-cols-2 gap-4 text-sm">
            <div>
              <span className="text-foreground font-semibold">Asiakas:</span>
              <p className="text-lg">{nimi || "Asiakas"}</p>
            </div>
            <div>
              <span className="text-foreground font-semibold">Huone:</span>
              <p className="text-lg">{huoneNumero}</p>
            </div>
            <div>
              <span className="text-foreground font-semibold">Yöt:</span>
              <p>{yot}</p>
            </div>
            <div className="bg-accent/15 col-span-2 rounded ">
              <span className="text-foreground font-semibold">Hinta: </span>
              <span className="text-md font-bold">
                {loppuhinta}€
              </span>
            </div>
          </div>
          <Button onClick={() => setNaytaVahvistus(false)} className="w-full">
            Uusi varaus
          </Button>
        </div>
      </div>
    );
  }

  return (
    <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
      <div className="border-border/50 border-b p-4 pb-2">
        <h2 className="text-sm font-medium">Tee varaus</h2>
      </div>
      <div className="p-4 pt-2">
        <form onSubmit={teeVaraus} className="space-y-6">
          <div className="space-y-2">
            <Label htmlFor="asiakasNimi">Asiakkaan nimi</Label>
            <Input
              id="asiakasNimi"
              value={nimi}
              onChange={(e) => setNimi(e.target.value)}
              placeholder="Kirjoita nimesi"
              required
            />
          </div>

          <div className="space-y-2">
            <Label htmlFor="huoneNumero">Huoneen numero (1-50)</Label>
            <Input
              id="huoneNumero"
              type="number"
              min="1"
              max="50"
              value={huoneNumero}
              onChange={(e) => setHuoneNumero(e.target.value)}
              required
            />
          </div>

          <div className="space-y-2">
            <Label htmlFor="yot">Yöiden lukumäärä</Label>
            <Input
              id="yot"
              type="number"
              min="1"
              value={yot}
              onChange={(e) => setYot(e.target.value)}
              required
            />
            <p className="text-muted-foreground text-xs">100€/yö</p>
          </div>

          <Button type="submit" className="w-full">
            Vahvista varaus
          </Button>
        </form>
      </div>
    </div>
  );
}
