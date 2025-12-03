"use client";

import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";

export function HakuLomake() {
  function kasitteleHaku(e: React.FormEvent) {
    e.preventDefault();
    /* TODO: Liitä /api/haku reitille */
  }

  const esimerkkiTulokset = [{ huone: 5, nimi: "Riyadh Muradi" }];

  return (
    <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
      <div className="border-border/50 border-b p-4 pb-2">
        <h2 className="text-sm font-medium">Etsi varauksia</h2>
      </div>
      <div className="space-y-4 p-4 pt-2">
        <form onSubmit={kasitteleHaku} className="space-y-4">
          <div className="space-y-2">
            <Label htmlFor="hakuNimi">Asiakkaan nimi</Label>
            <Input id="hakuNimi" placeholder="Riyadh Muradi" />
          </div>
          <Button type="submit" className="w-full">
            Hae
          </Button>
        </form>

        <div className="border-t pt-4">
          <h3 className="text-foreground mb-2 text-sm font-semibold">
            Esimerkkitulokset
          </h3>
          <div className="space-y-2">
            {esimerkkiTulokset.map((huone) => (
              <div
                key={huone.huone}
                className="bg-accent/10 border-border/50 flex justify-between rounded-xl border px-4 py-2"
              >
                <div>
                  <p className="text-foreground font-semibold">
                    Huone {huone.huone}
                  </p>
                </div>
                <div className="text-right">
                  <p className="text-muted-foreground text-sm">{huone.nimi}</p>
                </div>
              </div>
            ))}
          </div>
        </div>
      </div>
    </div>
  );
}
